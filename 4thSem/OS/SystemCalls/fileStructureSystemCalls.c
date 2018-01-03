#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// header file contains declarations for the types used by system-level calls to obtain file status or time information.
#include<sys/types.h>

// Accompanies fcntl() system call and provides symbolic constants for its arguments
// fcntl() can be used to retrieve or modify open file flags given a file descriptor
#include<fcntl.h>

// header file that is your code's entry point to various constant, type and function declarations that comprise the POSIX operating system API
// The Portable Operating System Interface is a family of standards specified by the IEEE Computer Society for maintaining compatibility between operating systems
#include<unistd.h>

// header provides a definition for struct passwd used for getting users from  /etc/passwd
#include <pwd.h>

#include <sys/stat.h>

char path[200];


// function declarations
void cowrc();
void dl();
void lu();
void amodown();
void mask();
void changeOwn();
void getPath();
int createFile();



int main(){

	int choice;

	loop:

	printf("==== MENU ===\n\n1.Create, Open, Write, Read, Close a File\n2. Duplicate, lseek\n3. Link, Unlink\n4. Access, Chmod\n5. Add a Mask\n6. Change ownership of file\n\n");
	printf("Enter choice: ");
	scanf("%d", &choice);

	switch (choice){

		case 1:
			cowrc();
			break;
		case 2:
			dl();
			break;
		case 3:
		    lu();
		case 4:
			amodown();
		case 5:
			mask();
			break;
		case 6:
			changeOwn();
	}


	goto loop;

	return 0;
}




/**
 * Get Path of file from user
 */
void getPath(){

	// get path
	printf("Specify path to the file:  ");
	getchar();
	gets(path);
}




/**
 * Open a file from the path
 * return -1 for error
 */
int createFile(){
	// CREATE

	// create file
	// S_IRWXU: Read, write, execute, search permissions for the owner
	int fileDescriptor = creat(path, S_IRWXU);

	if (fileDescriptor == -1){
		printf("=>=> Error while creating file\n");
		return -1;
	}

	printf("\n=>=> File created\n\n\n");

	// close the file
	close(fileDescriptor);

	return 0;
}





/**
 * Create, Open, Write, Read, Close a File
 */
void cowrc(){

	char wContent[500];
	char rContent[500];

	getPath();


	if (createFile() == -1){
		return;
	}


	// OPEN AND WRITE

	// open the file in write only mode
	int fileDescriptor = open(path, O_WRONLY);

	if (fileDescriptor == -1){
		printf("\n\n=>=> Error while opening file\n");
		return;
	}

	printf("=>=> File open\n");

	// get write content
	printf("Enter content to write to the file:  ");
	gets(wContent);

	// write into file
	int size = write(fileDescriptor, wContent, strlen(wContent));

	if (size == 0){
		printf("\n\n=>=> Write failed\n");
		return;
	}

	printf("\n=>=> Write Successful\n\n\n");

	// close the file
	close(fileDescriptor);




	// OPEN AND READ

	// open the file in read only mode
	fileDescriptor = open(path, O_RDONLY);

	if (fileDescriptor == -1){
		printf("\n\n=>=> Error while opening file\n");
		return;
	}

	printf("=>=> File open\n");

	int noOfChar;
	printf("Enter number of characters to read(< what you wrote in the file) : ");
	scanf("%d", &noOfChar);

	// read 10 characters from the file
	size = read(fileDescriptor, rContent, noOfChar);
	rContent[noOfChar] = '\0';

	if (size <= 0){
		printf("\n\n=>=> Read failed\n");
		return;
	}

	printf("\n=>=> Read Successful\n\n");

	// print out READ content
	printf("Content Read: %s\n\n\n", rContent);

	// close the file
	close(fileDescriptor);

}





/**
 *	dup: Duplicate a file descriptor, lseek: to move to nth byte in a file
 */
void dl(){

	char wContent[500];
	int cFileDescriptor;

	getPath();

	if (createFile() == -1){
		return;
	}


	// OPEN AND WRITE USING TWO FILE DESCRIPTORS SEEKING TO A POSITION

	// open the file in write only mode with append
	int fileDescriptor = open(path, O_WRONLY | O_APPEND);

	if (fileDescriptor == -1){
		printf("\n\n=>=> Error while opening file file\n");
		return;
	}

	printf("=>=> File open\n");


	// copy of file descriptor
	cFileDescriptor = dup(fileDescriptor);
	printf("\n\n=>=> Duplicate Created\n\n");

	// get write content
	printf("Enter content to write to the file using ORIGINAL DESCRIPTOR:  ");
	gets(wContent);

	// write into file
	int size = write(fileDescriptor, wContent, strlen(wContent));

	if (size == 0){
		printf("\n\n=>=> Write failed\n");
		return;
	}

	printf("\n=>=> Write Successful using ORIGINAL DESCRIPTOR\n\n\n");

	int offset;
	printf("Enter offset to write from using DUPLICATE DESCRIPTOR: ");
	scanf("%d", &offset);

	lseek (cFileDescriptor, offset, SEEK_SET);

	// get write content
	printf("Enter content to write to the file using DUPLICATE DESCRIPTOR:  ");
	getchar();
	gets(wContent);

	// write into file
	size = write(cFileDescriptor, wContent, strlen(wContent));

	if (size == 0){
		printf("\n\n=>=> Write failed\n");
		return;
	}

	printf("\n=>=> Write Successful using DUPLICATE DESCRIPTOR\n\n\n");

	// close the file
	close(fileDescriptor);
	close(cFileDescriptor);


}


/**
 * link: link two files to same memory location, unlink: unlink a file
 */
void lu(){

    char linkPath[200];

    // path
    getPath();

    if (createFile() == -1){
		return;
	}

    // get link path to get a link to new file's path
	printf("Enter a new path to link: ");
    gets(linkPath);


    // make a link to the path to linkPath
    if (link(path, linkPath) == -1){
        printf("\n=>=> Error has occured during creation of the link\n\n");
        return;
    }

    printf("\n=>=> Link successful\n\n\n");


    // unlink link path from path
    if (unlink(linkPath) == -1){
        printf("\n=>=> Error has occured during unlink\n\n");
        return;
    }

    printf("\n=>=> Unlink successful\n\n\n");


}


/**
 * access: check access permissions to a file, chmod: change permissions to access a file, chown: change ownership of the file
 */
void amodown(){

    getPath();

	// create with READ access for user
    int fileDescriptor = creat(path, S_IRUSR);
	if (fileDescriptor == -1){
		printf("=>=> Error while creating file\n");
	}
	close(fileDescriptor);


	// check existence of file
	if(access(path, F_OK) == 0){
	    printf("File exists created with only read access to user\n\n");
	}
	else{
	    printf("File doesn't exists\n\n");
	}

	// check read access
	if(access(path, R_OK) == 0){
	    printf("\n-- Read Access\n\n");
	}
	else{
	    printf("\n-- No Read Access\n\n");
	}

	// check write access
	if(access(path, W_OK) == 0){
	    printf("\n-- Write Access\n\n");
	}
	else{
	    printf("\n-- No Write Access\n\n");
	}




	// if you give invalid mode to chmod all read write access to file becomes void
	// change access to write for user
	if (chmod(path, S_IWUSR) == -1){
	    printf("\nUnable to change access\n\n");
	}


	printf("\n=>=> Access changed \n");

    // check read access
	if(access(path, R_OK) == 0){
	    printf("\n-- Read Access\n\n");
	}
	else{
	    printf("\n-- No Read Access\n\n");
	}

	// check write access
	if(access(path, W_OK) == 0){
	    printf("\n-- Write Access\n\n");
	}
	else{
	    printf("\n-- No Write Access\n\n");
	}


}



/**
 * umask: permissions in the umask are turned off from the mode argument to open(), creat(), etc
 */
void mask(){

	getPath();

	printf("\n=>=>Masked Read only user");
	umask(S_IRUSR);

	// create with write access for user
    int fileDescriptor = creat(path, S_IRUSR | S_IWUSR);
	if (fileDescriptor == -1){
		printf("=>=> Error while creating file\n");
	}
	close(fileDescriptor);

	printf("\n\nFile created with creat() Write permission to user and Read permission to user\n");



	// check read access
	if(access(path, R_OK) == 0){
	    printf("\n-- Read Access\n\n");
	}
	else{
	    printf("\n-- No Read Access\n\n");
	}

	// check write access
	if(access(path, W_OK) == 0){
	    printf("\n-- Write Access\n\n");
	}
	else{
	    printf("\n-- No Write Access\n\n");
	}


}


/**
 * chown: change ownership of a file
 */
void changeOwn(){

	getPath();

	// create with READ access for user
    int fileDescriptor = creat(path, S_IRUSR);
	if (fileDescriptor == -1){
		printf("=>=> Error while creating file\n");
	}
	close(fileDescriptor);

	printf("\n\nFile created with creat() Write permission to user and Read permission to user ()\n");


	// open file information and check owner info

	struct stat info;
	// obtain information about the named file
	stat(path, &info);
	printf("\noriginal owner was %d and group was %d\n", info.st_uid, info.st_gid);

	char username[100];
	printf("Enter username to change access: ");
	gets(username);

	uid_t uid;
    gid_t gid;
    struct passwd *pwd;
    struct group  *grp;


    pwd = getpwnam(username);

    if (pwd == NULL) {
        printf("\nUsername doesn't exists\n\n");
    }

    printf("\nowner id %d and group id %d\n", pwd->pw_uid, pwd->pw_gid);


	if (chown(path, 25, 0) != 0)
      perror("\n\nchown() error:");
    else {

		// obtain information about the named file
		stat(path, &info);
		printf("\nNew owner was %d and group was %d\n", info.st_uid, info.st_gid);

    }
}







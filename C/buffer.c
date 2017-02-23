#include <fcntl.h> // this library adds the file control options
#include <stdlib.h>// this library adds general purpose tools
#include <unistd.h>// adds the header file
#include <stdio.h>// adds file input and output
#define BUF_SIZE 500 //sets the buffer size
#define OUTPUT_MODE 0700 //sets the output mode
int main(int argc, char *argv[])// inisalises the class
{
    int in_fd, out_fd;// insalises 2 integers
    int characters=0;//number of characters
    int words=0;//numbers of words
    int bufferFill=0;//number of times the buffer has been filled
    int rd_size = 1, wr_size; //sets rd_size to 1 and insalises the integer wr$
    int i;//used for the loop
    char buf[BUF_SIZE]; //insalies a char taht is the buffer size
    if (argc != 3) // if the argc is not 3 the it does the following
        {
                printf("error1\n"); //shows there is an error
                exit(1); // exits the program
        }
    in_fd = open(argv[1], O_RDONLY); //open the file and puts it in the file d$
    if (in_fd < 0) // if the in file descriptor is more then 0 it does the fol$
        {
                printf ("error2\n");// shows there is an error
                exit(2);    // exits the program
        }
    out_fd = creat(argv[2],OUTPUT_MODE); //creates the file
    if (out_fd < 0) // if the out file descriptor is less then 0 it does the f$
        {
                printf ("error3\n");//shows there is an error
                exit(3); //exits the program
        }
    while (rd_size > 0) //loops through while the read size is more the 0
    {    
        rd_size = read(in_fd, buf,BUF_SIZE);//reads the size of the file
        bufferFill++;//increments the buffer
        characters = characters + rd_size;//adds to the amount of characters in the code
        for (i = 0; i<rd_size;i++)
        {
            if (buf[i] == ' ')
            {
                words++;//adds to the amount of words
            }
        }
        if (rd_size <0)//if the read size is more the 0 it does the following
                {
                        printf("error4\n");//shows there is and error
                        exit(4);//exits the program
                }
        wr_size = write(out_fd, buf, rd_size); //writes the file
        if (wr_size<0) //if the write size is less then or equal to 0 it doe$
                {
                        close(in_fd); //closes the in file descriptor
                        close(out_fd); //closes the out file descriptor
                        printf("error5\n");//shows there is an error
                        exit(5); //exits the program
                }
    }
    printf ("%d\n",characters);//next 3 lines print the number of characters, words and the timses the buffer i$
    printf ("%d\n",words);
    printf ("%d\n",bufferFill);
}

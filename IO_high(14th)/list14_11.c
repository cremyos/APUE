/*
 * Name : list14_11.c
 * Author : Lniper
 * Date : 2016-03-14
 * Aim : One implement of the readn() and writen().
 */
#include <apue.h>

ssize_t readn(int fd, void *ptr, size_t n)
{
	/*
	 * Read "n" bytes form a descriptor.
	 */
	size_t		nleft;
	sszie_t 	nread;
	
	nleft = n;
	while (nleft > 0) {
		if ((nread = read(fd, ptr, nleft)) < 0) {
			if (nleft == 0)
				return -1;			/* error, return -1 */
			else 
				break;				/* error, return amount read so far */
		} else if (nread == 0) {
			break;					/*  EOF */
		}
		nleft -= nread;
		ptr += nread;
	}
	
	return (n - nleft);				/* return >= 0 */
}

ssize_t writen(int fd, const void *ptr, size_t n)
{
	/*
	 * Write "n" bytes to a descriptor 
	 */
	size_t 		nleft;
	ssize_t		nwritten;
	
	nleft = n;
	while (nleft > 0) {
		if ((nwriten = write(fd, ptr, nleft)) < 0) {
			if (nleft == n)
				return -1;			/* error, return -1 */
			else
				break;				/* error, return amount written so far */
		} else if (nwritten == 0) {
			break;
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return (n - nleft);				/* return >= 0*/
}

/*
 * Name : list14_5.c
 * Author : Lniper
 * Date : 2016-03-11
 * Aim : Locking the file.
 */
#include <unistd.h>
#include <fcntl.h>

int lockfile(int fd)
{
	struct flock	fl;
	
	fl.l_type = F_WRLCK;
	fl.l_start = 0;
	fl.l_whence = SEEK_SET;
	fl.l_len = 0;
	return (fcntl(fd, F_SETLK, &fl));
}

#include <unistd.h>

/**
 * my_write - Custom implementation of the write function
 * @fd: File descriptor to write to
 * @buf: Buffer containing the data to write
 * @count: Number of bytes to write
 *
 * Return: The number of bytes written, or -1 on error
 */

ssize_t custom_write(int fd, const void *buf, size_t count)
{
  ssize_t written_bytes = 0;
  while (count > 0)
	{
    		ssize_t bytes_written = write(fd, buf, count);
    	if (bytes_written == -1) {
      		return -1;
    	}

    	written_bytes += bytes_written;
    	buf += bytes_written;
    	count -= bytes_written;
  	}

  	return written_bytes;
}

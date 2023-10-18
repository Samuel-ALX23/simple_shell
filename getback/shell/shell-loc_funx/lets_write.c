#include <unistd.h>

/**
 * my_write - Custom implementation of the write function
 * @fd: File descriptor to write to
 * @buf: Buffer containing the data to write
 * @count: Number of bytes to write
 *
 * Return: The number of bytes written, or -1 on error
 */
ssize_t my_write(int fd, const void *buf, size_t count)
{
        const char *char_buf = buf;
        size_t bytes_written = 0;
        ssize_t ret;

        while (bytes_written < count)
        {
                ret = write(fd, char_buf + bytes_written, count - bytes_written);
                if (ret == -1)
                {
                        return -1;
                }
                bytes_written += ret;
        }

        return bytes_written;
}

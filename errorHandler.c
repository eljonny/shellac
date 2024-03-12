/*
 * Original Author: Jonathan Hyry
 * Date Originally Written: 2/1/2012
 */

#include "shellTUIHdr.h"

char * getError ( void ) {

  // Store the error string here
  char *retStr = (char *)malloc(INPUT_ARG_SIZE*sizeof(char));

  // Figure out which error occurred:
  switch ( errno ) {

    case EPERM: return strcpy(retStr, "		 1	/* Operation not permitted */");
    case ESRCH: return strcpy(retStr, "		 3	/* No such process */");
    case EINTR: return strcpy(retStr, "		 4	/* Interrupted system call */");
    case ENXIO: return strcpy(retStr, "6	/* No such device or address */");
    case E2BIG: return strcpy(retStr, "7	/* Argument list too long */");
    case ENOEXEC: return strcpy(retStr, "	/* Exec format error */");
    case EBADF: return strcpy(retStr, "9	/* Bad file number */");
    case ECHILD: return strcpy(retStr, "10	/* No child processes */");
    case ENOTBLK: return strcpy(retStr, "15	/* Block device required */");
    case EBUSY: return strcpy(retStr, "16	/* Device or resource busy */");
    case EEXIST: return strcpy(retStr, "17	/* File exists */");
    case EXDEV: return strcpy(retStr, "18	/* Cross-device link */");
    case ENODEV: return strcpy(retStr, "19	/* No such device */");
    case EISDIR: return strcpy(retStr, "21	/* Is a directory */");
    case EINVAL: return strcpy(retStr, "22	/* Invalid argument */");
    case ENFILE: return strcpy(retStr, "23	/* File table overflow */");
    case EMFILE: return strcpy(retStr, "24	/* Too many open files */");
    case ENOTTY: return strcpy(retStr, "25	/* Not a typewriter */");
    case ETXTBSY: return strcpy(retStr, "26	/* Text file busy */");
    case EFBIG: return strcpy(retStr, "27	/* File too large */");
    case ENOSPC: return strcpy(retStr, "28	/* No space left on device */");
    case ESPIPE: return strcpy(retStr, "29	/* Illegal seek */");
    case EROFS: return strcpy(retStr, "30	/* Read-only file system */");
    case EMLINK: return strcpy(retStr, "31	/* Too many links */");
    case EPIPE: return strcpy(retStr, "32	/* Broken pipe */");
    case EDOM: return strcpy(retStr, "33	/* Math argument out of domain of func */");
    case ERANGE: return strcpy(retStr, "		34	/* Math result not representable */");
    case EACCES: return strcpy(retStr, "Search permission is denied for one\nof the components \
                                        of path. (See also path_resolution(7).)\n");
    case EFAULT: return strcpy(retStr, "path points outside your accessible address space.\n");
    case EIO: return strcpy(retStr, "An I/O error occurred.\n");
    case ELOOP: return strcpy(retStr, "Too many symbolic links were encountered in resolving \
                                       path.\n");
    case ENAMETOOLONG: return strcpy(retStr, "path is too long.\n");
    case ENOENT: return strcpy(retStr, "The file does not exist.\n");
    case ENOMEM: return strcpy(retStr, "Insufficient kernel memory was available.\n");
    case ENOTDIR: return strcpy(retStr, "A component of path is not a directory.\n");
    case EAGAIN: return strcpy(retStr, "The system lacked the necessary resources to create \
                                        another process,\nor the system-imposed limit on the \
                                        total number of processes under execution\nsystem-wide \
                                        or by a single user {CHILD_MAX} would be exceeded.");
    case EBADR: return strcpy(retStr, "Invalid request descriptor");
    case EXFULL: return strcpy(retStr, "/* Exchange full */");
    case ENOANO: return strcpy(retStr, "/* No anode */");
    case EBADRQC: return strcpy(retStr, "/* Invalid request code */");
    case EBADSLT: return strcpy(retStr, "/* Invalid slot */");
    case EDEADLOCK: return strcpy(retStr, "Deadlock detected");
    case EBFONT: return strcpy(retStr, "		59	/* Bad font file format */");
    case ENOSTR: return strcpy(retStr, "60	/* Device not a stream */");
    case ENODATA: return strcpy(retStr, "61	/* No data available */");
    case ENOSR: return strcpy(retStr, "63	/* Out of streams resources */");
    case ENOLINK: return strcpy(retStr, "67	/* Link has been severed */");
    case EADV: return strcpy(retStr, "68	/* Advertise error */");
    case ESRMNT: return strcpy(retStr, "	69	/* Srmount error */");
    case EBADMSG: return strcpy(retStr, "74	/* Not a data message */");
    case EOVERFLOW: return strcpy(retStr, "75	/* Value too large for defined data type */");
    case EBADFD: return strcpy(retStr, "	77	/* File descriptor in bad state */");
    case ELIBACC: return strcpy(retStr, "79	/* Can not access a needed shared library */");
    case ELIBBAD: return strcpy(retStr, "80	/* Accessing a corrupted shared library */");
    case ELIBSCN: return strcpy(retStr, "		81	/* .lib section in a.out corrupted */");
    case ELIBMAX: return strcpy(retStr, "		82	/* Attempting to link in too many shared \
                                         libraries */");
    case ELIBEXEC: return strcpy(retStr, "	83	/* Cannot exec a shared library directly */");
    case EILSEQ: return strcpy(retStr, "		84	/* Illegal byte sequence */");
    case ERESTART: return strcpy(retStr, "85	/* Interrupted system call should be restarted */");
    case ESTRPIPE: return strcpy(retStr, "86	/* Streams pipe error */");
    case EUSERS: return strcpy(retStr, "		87	/* Too many users */");
    case ENOTSOCK: return strcpy(retStr, "88	/* Socket operation on non-socket */");
    case EDESTADDRREQ: return strcpy(retStr, "89	/* Destination address required */");
    case EMSGSIZE: return strcpy(retStr, "	90	/* Message too long */");
    case ETOOMANYREFS: return strcpy(retStr, "109	/* Too many references: cannot splice */");
    case EALREADY: return strcpy(retStr, "	114	/* Operation already in progress */");
    case EINPROGRESS: return strcpy(retStr, "	115	/* Operation now in progress */");
    case ESTALE: return strcpy(retStr, "		116	/* Stale NFS file handle */");
    case EUCLEAN: return strcpy(retStr, "		117	/* Structure needs cleaning */");
    case EISNAM: return strcpy(retStr, "		120	/* Is a named type file */");
    case EREMOTEIO: return strcpy(retStr, "	121	/* Remote I/O error */");
    case EDQUOT: return strcpy(retStr, "		122	/* Quota exceeded */");
    case ENOMEDIUM: return strcpy(retStr, "	123	/* No medium found */");
    case EMEDIUMTYPE: return strcpy(retStr, "Wrong medium type.");
    case ECANCELED: return strcpy(retStr, "Operation canceled.");
    case EOWNERDEAD: return strcpy(retStr, "Owner died");
    case ENOTRECOVERABLE: return strcpy(retStr, "State unrecoverable.");
    case ERFKILL: return strcpy(retStr, "Operation not possible because of rfkill.");
    default: return strcpy(retStr, "Unknown error");
  }
}

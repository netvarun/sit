#include "sit.h"

static FILE *logfile = NULL;

void
sit_log(const char *level, const char *format, ...) {
	va_list args;
  va_start(args, format);
  if(logfile) {
    time_t timer;
    char buffer[25];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    
    strftime(buffer, 25, "%Y:%m:%dT%H:%M:%S", tm_info);
    
    fprintf(logfile, "[%s] [%d] [%s] ", level, getpid(), buffer);
    
    vfprintf(logfile, format, args);
    fprintf(logfile, "\n");
  }
}

void
set_logger(FILE *file) {
  logfile = file;
}
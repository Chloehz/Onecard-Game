#include "project.h"

void clear_screen(){
    #if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
	    if(system("cls")){};
    #elif defined(__linux__) || defined(__APPLE__)
        if(system("clear")){};
    #endif
}

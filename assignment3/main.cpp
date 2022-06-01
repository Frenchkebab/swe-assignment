#include <iostream>
#include <string>
#include "assignment3.h"

#define MAX_STRING 32

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void join();
void program_exit();

FILE *in_fp, *out_fp;

using namespace std;

int main() {
    FILE *in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE *out_fp = fopen(OUTPUT_FILE_NAME, "W+");

    doTask();

    return 0;

}

void doTask() {

    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    while(!is_program_exit) {

        // cin.getline();

        switch(menu_level_1) {
            case 1: {
                switch(menu_level_2) {
                    case 1: {
                        
                    }

                    case 2: {

                    }
                }
                
            }

            case 2: {
                switch(menu_level_2) {
                    case 1: {

                    }

                    case 2: {
                        
                    }

            }

            case 3: {
                switch(menu_level_2) {
                    case 1: {

                    }

                    case 2: {
                        
                    }

                    case 3: {

                    }

            }

            case 4: {
                switch(menu_level_2) {
                    case 1: {

                    }

                    case 2: {
                        
                    }
                    
                    case 3: {

                    }

                    case 4: {

                    }

            }

            case 5: {
                switch(menu_level_2) {
                    case 1: {

                    }

            }
            
            case 6: {
                switch(menu_level_2) {
                    case 1: {

                    }
            }
        }

        
    }
}


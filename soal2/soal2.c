#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <wait.h>
#include <time.h>

int main(){

    /*question a*/

    int stat_1, stat_2, stat_3;
    
    pid_t child_id;
    child_id = fork();
    
    if(child_id < 0) 
    exit(0);
    
    if(child_id == 0){
        char *arg[] = {"unzip", "-o", "-q", "/home/julius/modul2/pets.zip", "-d", "/home/julius/modul2/petshop", NULL};
        execv("/usr/bin/unzip", arg);}
    
    while(wait(&stat_1) > 0);
    
    DIR *directory;
    struct dirent *entry;
    directory = opendir("/home/julius/modul2/petshop");
    
    while((entry = readdir(directory)) != NULL) {
        if((entry->d_type == DT_DIR) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            pid_t child_id;
            child_id = fork();
            if(child_id < 0) exit(0);
            if(child_id == 0) {
                char folder[300];
                sprintf(folder, "/home/julius/modul2/petshop/%s", entry->d_name);
                char *arg[] = {"rm", "-r", folder, NULL};
                execv("/bin/rm", arg);
            }
        }
    }
    /*end of question a*/

    /*question b*/

    while(wait(&stat_2) > 0);

    DIR *directory2;
    struct dirent *entry2;
    directory2 = opendir("/home/julius/modul2/petshop");

    char folder[100][300];
    int index = 0;
    while((entry2 = readdir(directory2)) != NULL){
        if(entry2->d_type == DT_REG){
            char temp[300], temp2[300];
            memset(folder[index], 0, sizeof(folder[index]));
            memset(temp2, 0, sizeof(temp2));
            strcpy(temp, entry2->d_name);
            int i, found = 0;

            for(i = 0; i < strlen(temp); i++){
                if(temp[i] == ';') break;
                temp2[i] = temp[i];
            }
            
            for(i = 0; i < index && found == 0; i++)
                if(strcmp(folder[i], temp2) == 0)
                    found = 1;
            
            if(found == 0){
                strcpy(folder[index], temp2);
                index++;
            }
        }
    }
    
    int i;
    for(i = 0; i < index; i++){
        pid_t child_id;
        child_id = fork();

        if(child_id < 0) 
	exit(0);
        if(child_id == 0){
            char temp[300];
            sprintf(temp, "/home/julius/modul2/petshop/%s", folder[i]);
            char *arg[] = {"mkdir", temp, NULL};
            execv("/bin/mkdir", arg);
        }
    }
    /*end of question b*/

    /*question c*/
    
    while(wait(&stat_3) > 0);
    
    DIR *directory3;
    struct dirent *entry3;
    directory3 = opendir("/home/julius/modul2/petshop");
    
    while((entry3 = readdir(directory3)) != NULL){
    
        if(entry3->d_type == DT_REG){
        
            char temp[300];
            char temp2_type[300], temp2_name[300], temp2_old[300];
            char temp3_type[300], temp3_name[300], temp3_old[300];
            memset(temp2_type, 0, sizeof(temp2_type));
            memset(temp2_name , 0, sizeof(temp2_name));
            memset(temp2_old , 0, sizeof(temp2_old));
            memset(temp3_type, 0, sizeof(temp3_type));
            memset(temp3_name , 0, sizeof(temp3_name));
            memset(temp3_old , 0, sizeof(temp3_old));
            strcpy(temp, entry3->d_name);
            
            int i, a, found = 0, same = 0;
            for(i = 0; i < strlen(temp); i++) {
                if(temp[i] == ';') break;
                temp2_type[i] = temp[i];
            }
            i++; a = i;
            
            for(; i < strlen(temp); i++){
                if(temp[i] == ';') break;
                temp2_name[i-a] = temp[i];
            }
            
            i++; a = i;
            for(; i < strlen(temp); i++){
                if(temp[i] == '_' || (temp[i] == '.' && temp[i+1] == 'j')) break;
                temp2_old[i-a] = temp[i];
            }
            /*continued*/
            
            /*question d*/
            
            if(temp[i] == '_') {
                i++; a = i;
                
                for(; i < strlen(temp); i++) {
                    if(temp[i] == ';') break;
                    temp3_type[i-a] = temp[i];
                }
                i++; a = i;
                
                for(; i < strlen(temp); i++) {
                    if(temp[i] == ';') break;
                    temp3_name[i-a] = temp[i];
                }
                i++; a = i;
                
                for(; i < strlen(temp); i++) {
                    if(temp[i] == '.' && temp[i+1] == 'j') break;
                    temp3_old[i-a] = temp[i];
                }
                
                same = 1;
            }
            /*continued*/
            
            /*continued of question c*/
    	    int stat, stat_2;
    
    	    pid_t child_id;
    	    child_id = fork();
    
    	    if(child_id < 0) 
    	    exit(0);
    	    if(child_id == 0){
    		char from[300], to[300];
        	sprintf(from, "/home/julius/modul2/petshop/%s", entry3->d_name);
        	sprintf(to, "/home/julius/modul2/petshop/%s/%s", temp2_type, temp2_name);
        	char *arg[] = {"cp", "-r", from, to, NULL};
        	execv("/bin/cp", arg);
        	}
           /*end of question c*/
           
           /*question e*/
           
           while(wait(&stat) > 0);
           char keterangan[300];
           sprintf(keterangan, "/home/julius/modul2/petshop/%s/keterangan.txt", temp2_type);
           FILE *file;
           file = fopen(keterangan, "a+");
           fprintf(file, "nama : %s\n", temp2_name);
           fprintf(file, "umur : %s tahun\n\n", temp2_old);
           fclose(file);
           /*continued*/
           
           /*continued of question d*/
           if(same == 1){
           
    	   pid_t child_id;
    	   child_id = fork();
    	   
    	   if(child_id < 0)
    	   exit(0);
    	   if(child_id == 0){
		char from[300], to[300];
		sprintf(from, "/home/julius/modul2/petshop/%s", entry3->d_name);
		sprintf(to, "/home/julius/modul2/petshop/%s/%s", temp3_type, temp3_name);
		char *arg[] = {"cp", "-r", from, to, NULL};
		execv("/bin/cp", arg);
    		}
    	    	   
    	   /*continued of question e*/
    	   while(wait(&stat_2) > 0);
                char keterangan[300];
                sprintf(keterangan, "/home/julius/modul2/petshop/%s/keterangan.txt", temp3_type);
                FILE *file;
                file = fopen(keterangan, "a+");
                fprintf(file, "nama : %s\n", temp3_name);
                fprintf(file, "umur : %s tahun\n\n", temp3_old);
                fclose(file);
                /*end of question e*/
            }
            /*end of question d*/
        }
   }
}

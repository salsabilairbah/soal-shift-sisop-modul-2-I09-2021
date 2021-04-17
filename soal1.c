#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){
pid_t proc;
int stat;
if(fork()==0){
	char *argv[] = {"mkdir", "-p","Musyik","Pyoto","Fylm", NULL};
	execv("/bin/mkdir",argv);
}
if(fork()==0){
	while(wait(&stat)>0);
if(fork()==0)
//download file nya
	execl("/usr/bin/wget", "wget","--no-check-certificate","https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","-O","music.zip","", NULL);
	while(wait(&stat)>0);
if(fork()==0){
//unzip filenya
	execl("/usr/bin/unzip","unzip","music","-d","./Musyik",NULL);
}
if(fork()==0){
	while(wait(&stat)>0)
//masih belum
	execl("/usr/bin/mv","mv","./Musyik/MUSIK/*","./Musyik",NULL);
}
	while(wait(&stat)>0);
if(fork()==0)
	execl("/usr/bin/wget", "wget","--no-check-certificate","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O","poto.zip","", NULL);
	while(wait(&stat)>0);
if(fork()==0){
	execl("/usr/bin/unzip","unzip","poto","-d","./Pyoto",NULL);
}
if(fork()==0){
	while(wait(&stat)>0)
	execl("/usr/bin/mv","mv","./Pyoto/FOTO/*","./Pyoto",NULL);
}

	while(wait(&stat)>0);
if(fork()==0)
	execl("/usr/bin/wget", "wget","--no-check-certificate","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","-O","film.zip","", NULL);
	while(wait(&stat)>0);
if(fork()==0){
	execl("/usr/bin/unzip","unzip","film","-d","./Fylm",NULL);
}
if(fork()==0){
	while(wait(&stat)>0)
	execl("/usr/bin/mv","mv","./Fylm/FILM/*","./Fylm",NULL);
}
}
	while(wait(&stat)>0);
	execl("/usr/bin/zip","zip","-rm","Lopyu_Stevany.zip","Fylm","Pyoto","Musyik",NULL);

}

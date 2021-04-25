# soal-shift-sisop-modul-2-I09-2021

NUMBER 1
For number 1, i still can answer from a to d. but for e and f, i still confused and still figured it out. 
When i did the assignment, I got a little struggle about the output, i put while before if and the output 
only show musik.zip, musyik,fylm,pyoto, but only musyik contains the files and also not stop. so I try 
to put the while inside if and when I run it, the output turned out right. I use fork(), wait()
fork() use to make two process which run concurrently. the function of wait() is blocking the calling 
process until one of its child processes exits or a signal is received. stat greater than 0, 
so it is not null, so it stored stat information.

NUMBER 2

For number 2, we get a zip containing a large number of pet photos and we are instructed to categorize the photos of the pets.

a) We need to extract the given zip into the folder in "home/[user]/modul2/petshop". Because there are unimportant folders, so we need to delete that unnecessary folders

![image](https://user-images.githubusercontent.com/77782259/115987187-26f75c00-a5de-11eb-91b8-6a91981201b7.png)

First we declare the status for using wait(), then we use fork and execv to call the pid and child id so the process will be run well. Then, unzip the given zip into the folder that mentioned before.

![image](https://user-images.githubusercontent.com/77782259/115987297-ae44cf80-a5de-11eb-82a8-7fdf1b5a4edd.png)

After unzip the file, there are some unnecessary folders that we need to remove it, for that case we use the strcmp to scan whether the folder needer or not by finding the "." and ".." it means that we find the folder using that name, so we supposed to delete it. And because we do it again & again, we use while for looping and wait() to check the runned process is true or false.

b) We need to categorized the pet in the zip based on the pet's species and create a folder for each species in the zip. For example: Cats will be stored in "/petshop/cat", turtles will be stored in "/petshop/turtle", dogs will be stored in "petshop/dog", and so on until each species get each folders.

![image](https://user-images.githubusercontent.com/77782259/115987620-04fed900-a5e0-11eb-91ed-68d24552b486.png)

Because we need to check it recursively, we'll use while. Then to help us to become easier on the naming and checking the pets, we use 2 dimension of array to store the species name of pets. Because each picture format is "species;pet_name;pet_old.jpg" and for each category separated by using ";" so we'll use it to make the comparison between each other.

![image](https://user-images.githubusercontent.com/77782259/115987838-011f8680-a5e1-11eb-8592-9d8ef5ec93cc.png)

Then, we create the folder for each species that we already kept them.

c) After the folders are created, we should to move the photos to the folder based on its species and rename the photo with the pet's name. For example "/petshop/cat/joni.jpg", "petshop/betta/bella.jpg" and so on.

![image](https://user-images.githubusercontent.com/77782259/115988027-f31e3580-a5e1-11eb-99e8-7b417904f1a8.png)

Because we need to check it recursively, we'll use while. Then we create 2 dimension arrays based on their type, name and old. In here type means what species they are, name is for their names, and old is for their olds. Then because each picture format is "species;pet_name;pet_old.jpg" and for each category separated by using ";" so we'll use it to make the comparison between each other like before.

![image](https://user-images.githubusercontent.com/77782259/115988116-63c55200-a5e2-11eb-9ccb-7bd1fc06922e.png)

After that, we move each photo who have been catagorized based on their species and we jump to the each folder then rename of each photo based on its pet name.

d) Because 1 photo may have more than 1 pet in it, photos must be moved to each corresponding category. For example: photo with the name "dog;baro;1_cat;joni;2.jpg" is moved to the folder "/petshop/cat/joni.jpg" and "/petshop/dog/baro.jpg" and so on.

![image](https://user-images.githubusercontent.com/77782259/115988428-e6024600-a5e3-11eb-993b-0b13531c5173.png)

Because each picture format is "species;pet_name;pet_old.jpg" and for each category separated by using ";" so we'll use it to make the comparison between each other like before. But if we found a new one, i mean the picture that has "underscore / underline" it means that the picture have more than 1 species in its photo, so we need to stored them in array and overwrite the variable "same"

![image](https://user-images.githubusercontent.com/77782259/115988469-177b1180-a5e4-11eb-9911-f319190d3dce.png)

Then, moved the photo before into the 2 folders of each category based on its species.

e) In each folder, we create a file "keterangan.txt" that contains names and ages of all the pets in the folder. The format of "keterangan.txt" must be identical with the example below:

nama : joni
umur : 3 tahun

nama : miko
umur : 2 tahun

![image](https://user-images.githubusercontent.com/77782259/115988560-88bac480-a5e4-11eb-9173-7c181bc90389.png)

First, we need an array to kept all of the formatting before in the file then create the .txt file and fill it with the format as mentioned before. The picture above is for the first line formatting and the picture below is for the second line formatiing.

![image](https://user-images.githubusercontent.com/77782259/115988632-d33c4100-a5e4-11eb-9907-c25d8949f296.png)

The challenges of working in practicum this time is on the point c, that the question asked to "move the photo" but i use the copy and remove one due to i don't know how to operate them using "move".

#include <stdio.h>
#include <string.h>

#define STRING_LEN 20
#define PLAYLIST_LEN 20
typedef struct {
    char artist[STRING_LEN];
    char title[STRING_LEN];
    char album[STRING_LEN];
    int rating;
}Song;



int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles);
int is_member(Song playlist[], int len, char* title);
void sort(Song playlist[], int len);
int do_swap(Song first, Song second);
void print(Song playlist[], int len);

/**
 * Example call
 *
 * ./a.out input1.txt input2.txt
 *
 * There can be any number of input files
 *  
 *
 * ./a.out input1.txt input2.txt . . . input1000.txt
 */
int main(int argc, char* argv[]) {
	Song playlist[PLAYLIST_LEN];
	int len = build_playlist(playlist, argv+1, argc-1);

    if (argc < 2) {
        printf("Incorrect number of command line arguments\n");
        printf("Correct usage: %s <input 1> <input 2> . . . <input n>\n", argv[0]);
        return -1;
    }
   
    if (len == -1) {
        printf("Invalid input: multiple songs with the same title");
        return 0;
    }

    sort(playlist, len);
    print(playlist, len);

    return 0;
}

/* Possible points : 15
 *
 * Param playlist  : An empty array of song structs
 * Param inputFile : An array of strings, each one representing one input file
 * Param numInputFiles : The number of files in the inputFile array
 *
 * return The length of the input file or -1 if the function fails
 *
 * This method should read the songs from each file into the playlist array. 
 * If there are more than PLAYLIST_LEN number of songs then only the the first 
 * PLAYLIST_LEN number of songs should be read in. This method will call the 
 * is_member function on each song. The playlist cannot hold duplicates and if
 * it discovers two songs with the same title then it should error out and 
 * return -1.
 *
 * IMPORTANT : Input files do not have their length at the top
 *  ex) 
 *
 * Beatles AbbeyRoad Because 10
 * Beatles Anthology1 Shout 12
 * . . . 
 */
int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles) {
	int i,num=0;
    for(i=0;i<numInputFiles;i++){
		FILE* file=fopen(inputFiles[i],"r");
		if(file==NULL){
			printf("Can not open the file\n");
			exit(-1);
		}
		while(!feof(file)){
			fscanf(file,"%s%s%s%d",playlist[num].artist,playlist[num].album,playlist[num].title,&playlist[num].rating);
			if(is_member(playlist,num,playlist[num].title)){
				return -1;
			}
			if(num++>PLAYLIST_LEN){
				break;
			}
		}
	}
	return num;
}

/* Possible points : 10
 *
 * Param playlist : An array of songs
 * Param len : The number of songs in the param array
 * Param title : The title of a song
 *
 * return 1 if the title is already in the playlist array 0 otherwise
 */
int is_member(Song playlist[], int len, char* title) {
	int i;
    for(i=0;i<len;i++){
		if(strcmp(title,playlist[i].title)==0){
			return 1;
		}
	}
	return 0;
}   

/* Possible points : 10
 *
 * Param playlist : a list of songs
 * Param len : the number of songs in the playlist array
 *
 * Sorts the playlist based off of artist, then album, and then title.
 * The do_swap method should be used to determine if two songs should be swapped
 */
void sort(Song playlist[], int len) { 
    int i,j;
	Song temp;
	Song *current=playlist;
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(do_swap(playlist[i],playlist[j])==1){
				temp=*(current+i);
				*(current+i)=*(current+j);
				*(current+j)=temp;
			}
		}
	}
}

/* Possible points : 10
 *
 * Param first : A song
 * Param second : A different song
 *
 * return 1 if the the songs should be swapped, 0 otherwise
 */
int do_swap(Song first, Song second) {
    if(strcmp(first.artist,second.artist)>0){
		return 1;
	}
	else if(strcmp(first.artist,second.artist)==0&&strcmp(first.album,second.album)>0){
		return 1;
	}
	else if(strcmp(first.album,second.album)==0&&strcmp(first.title,second.title)>0){
		return 1;
	}
	return 0;
}

/* Possible points : 5
 *
 * Param playlist : An array of songs
 * Param len : The number of songs in the playlist array
 * 
 * Prints out the sorted playlist
 * artists should have a padding of 10, abum a padding of 12, 
 * title a padding of 10 and rating a padding of 4
 */
void print(Song playlist[], int len) { 
	int i;
    for(i=0;i<len;i++){
		printf("%s %s %s %d\n",playlist[i].artist,playlist[i].album,playlist[i].title,playlist[i].rating);
	}
}
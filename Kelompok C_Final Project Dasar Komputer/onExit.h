#ifndef ONEXIT_H
#define ONEXIT_H
 
void keluar(){
	FILE* tulisAutoPId;
	tulisAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(tulisAutoPId, "%d", autoPId);
    fclose(tulisAutoPId);
}
 
#endif


#include <stdio.h> 
#define MAX_BLOCKS 100 
#define MAX_SIZE 1000 

int block_size[MAX_BLOCKS]; 
int allocated[MAX_BLOCKS]; 

int allocate_memory(int process_size) 
{ 
	int block_idx = -1;
	for (int i = 0; i < MAX_BLOCKS; i++) { 
		if (allocated[i] == 0 && block_size[i] >= process_size) { 
			block_idx = i; 
			allocated[i] = 1; 
			printf("Allocated block %d of size %d for process of size %d\n", 
				block_idx, block_size[block_idx], process_size); 
			break; 
		} 
	} 	
	if (block_idx == -1) { 
		printf("No suitable block available for process of size %d\n", 
			process_size); 
	} 
	return block_idx; 
} 
void deallocate_memory(int block_idx) 
{ 
	if (allocated[block_idx]) { 
		allocated[block_idx] = 0; 
		printf("Deallocated block %d of size %d\n", 
			block_idx, block_size[block_idx]); 
	} else { 
		printf("Block %d was already deallocated\n", block_idx); 
	} 
} 
int main() 
{ 
	for (int i = 0; i < MAX_BLOCKS; i++) { 
		block_size[i] = MAX_SIZE / (i + 1); 
	}
	int p1 = allocate_memory(100); 
	int p2 = allocate_memory(200); 
	int p3 = allocate_memory(300); 
	deallocate_memory(p1); 
	deallocate_memory(p2); 
	deallocate_memory(p3); 	
	return 0; 
}

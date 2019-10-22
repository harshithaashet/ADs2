#include <stdint.h>
#include <assert.h>
#include "heap.h"

void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (data[idx] <= data[idx+1]);		
	}
}

void test_heap()
{
	int32_t data[] = { 0, 1130,1130,1300,1330};
	Heap heap = heap_new(data, 1159);	
	heap_insert(&heap, 1200);
	heap_test(&heap);
	assert(heap_get_max(&heap) ==1150);
	assert(heap_extract_max(&heap) == 1150);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);

	heap_sort(&heap);
	test_sort(heap.data, 10);

}

int main()
{
	test_heap();
        return 0;

	

}

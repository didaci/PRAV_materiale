
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

typedef struct {
    int v1;
    int v2;
    int v3;
} Elemento;

typedef struct {
    Elemento* dati;
    int heap_size;
} MinHeap;

typedef struct {
    Elemento* data;
    int FRONT;
    int TAIL;
    int capacity;
    int size;
} Queue;


// funzioni di servizio
void printArray(Elemento** v, int n){

    for (int i=0; i<n; i++){
        printf("vettore[%d] = { v1 = %d, v2 = %d, v3 = %d }\n",
              i,
              v[i]->v1,
              v[i]->v2,
              v[i]->v3);
    }
    printf("\n");
}


void generaVettoreInput(Elemento vettore_input[], int n) {
    int valori_v1[N] = {7, 1, 2, 0, 9, 6, 4, 5, 8, 3};

    srand(42);   // seed fisso per rendere l'esperimento replicabile

    for (int i = 0; i < n; i++) {
        vettore_input[i].v1 = valori_v1[i];
        vettore_input[i].v2 = rand() % 100 + 1;
        vettore_input[i].v3 = rand() % 100 + 1;
    }
}


Elemento** creaVettoreDaInput(const Elemento vettore_input[], int n) {
    Elemento** v = malloc(n * sizeof(Elemento*));
    if (v == NULL) {
        perror("Errore allocazione vettore");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        v[i] = malloc(sizeof(Elemento));
        if (v[i] == NULL) {
            perror("Errore allocazione elemento");

            for (int j = 0; j < i; j++) {
                free(v[j]);
            }
            free(v);

            return NULL;
        }

        v[i]->v1 = vettore_input[i].v1;
        v[i]->v2 = vettore_input[i].v2;
        v[i]->v3 = vettore_input[i].v3;
    }

    return v;
}


void liberaVettore(Elemento** v, int n) {
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
}


void printMinHeap(MinHeap* heap) {
    for (int i = 0; i < heap->heap_size; i++) {
        printf("heap[%d] = { v1 = %d, v2 = %d, v3 = %d }\n",
               i,
               heap->dati[i].v1,
               heap->dati[i].v2,
               heap->dati[i].v3);
    }
    printf("\n");
}


void printElemento(Elemento el) {
    printf("{ v1 = %d, v2 = %d, v3 = %d }", el.v1, el.v2, el.v3);
}


void merge(Elemento** v, int p, int q, int r) {
    int i;
    int i_left, i_right;
    int len_left = q - p + 1;
    int len_right = r - q;
    Elemento* v_left[len_left];
    Elemento* v_right[len_right];

    for (i = 0; i < len_left; i++) {
        v_left[i] = v[p + i];
    }
    for (i = 0; i < len_right; i++) {
        v_right[i] = v[q + i + 1];
    }

    i_left = 0;
    i_right = 0;
    i = p;

    while (i_left < len_left && i_right < len_right) {
        if (v_left[i_left]->v1 <= v_right[i_right]->v1) {
            v[i] = v_left[i_left];
            i++;
            i_left++;
        } else {
            v[i] = v_right[i_right];
            i++;
            i_right++;
        }
    }

    while (i_left < len_left) {
        v[i] = v_left[i_left];
        i++;
        i_left++;
    }
    while (i_right < len_right) {
        v[i] = v_right[i_right];
        i++;
        i_right++;
    }
}


void merge_sort(Elemento** v, int p, int r) {
    int q;

    if (p < r) {
        q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}


int gt_v2(Elemento* el1, Elemento* el2) {
    return el1->v2 > el2->v2;
}


int gt_somma(Elemento* el1, Elemento* el2) {
    return (el1->v1 + el1->v2 + el1->v3) > (el2->v1 + el2->v2 + el2->v3);
}


void merge_strategy(Elemento** v, int p, int q, int r, int (*gt)(Elemento*, Elemento*)) {
    int i;
    int i_left, i_right;
    int len_left = q - p + 1;
    int len_right = r - q;
    Elemento* v_left[len_left];
    Elemento* v_right[len_right];

    for (i = 0; i < len_left; i++) {
        v_left[i] = v[p + i];
    }
    for (i = 0; i < len_right; i++) {
        v_right[i] = v[q + i + 1];
    }

    i_left = 0;
    i_right = 0;
    i = p;

    while (i_left < len_left && i_right < len_right) {
        if (!gt(v_left[i_left], v_right[i_right])) {
            v[i] = v_left[i_left];
            i++;
            i_left++;
        } else {
            v[i] = v_right[i_right];
            i++;
            i_right++;
        }
    }

    while (i_left < len_left) {
        v[i] = v_left[i_left];
        i++;
        i_left++;
    }
    while (i_right < len_right) {
        v[i] = v_right[i_right];
        i++;
        i_right++;
    }
}


void mergesort_strategy(Elemento** v, int p, int r, int (*gt)(Elemento*, Elemento*)) {
    int q;

    if (p < r) {
        q = (p + r) / 2;
        mergesort_strategy(v, p, q, gt);
        mergesort_strategy(v, q + 1, r, gt);
        merge_strategy(v, p, q, r, gt);
    }
}


int binarySearchV2(Elemento** v, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int idx_middle = left + (right - left) / 2;

        if (v[idx_middle]->v2 == target) {
            return idx_middle;
        }

        if (v[idx_middle]->v2 < target) {
            left = idx_middle + 1;
        } else {
            right = idx_middle - 1;
        }
    }

    return -1;
}


int parent(int i) {
    return (i - 1) / 2;
}


int left(int i) {
    return 2 * i + 1;
}


int right(int i) {
    return 2 * (i + 1);
}


void min_heapify(MinHeap* heap, int i) {
    int l, r, idx_min;
    Elemento min;
    Elemento* A = heap->dati;

    l = left(i);
    r = right(i);

    if (l < heap->heap_size && A[l].v1 < A[i].v1) {
        idx_min = l;
    } else {
        idx_min = i;
    }

    if (r < heap->heap_size && A[r].v1 < A[idx_min].v1) {
        idx_min = r;
    }

    if (idx_min != i) {
        min = A[idx_min];
        A[idx_min] = A[i];
        A[i] = min;
        min_heapify(heap, idx_min);
    }
}


void build_min_heap(MinHeap* heap) {
    for (int i = heap->heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i);
    }
}


MinHeap creaMinHeapDaVettore(Elemento** v, int n) {
    MinHeap heap;

    heap.dati = malloc(n * sizeof(Elemento));
    if (heap.dati == NULL) {
        perror("Errore allocazione min heap");
        heap.heap_size = 0;
        return heap;
    }

    heap.heap_size = n;

    for (int i = 0; i < n; i++) {
        heap.dati[i] = *v[i];
    }

    build_min_heap(&heap);

    return heap;
}


void liberaMinHeap(MinHeap* heap) {
    free(heap->dati);
    heap->dati = NULL;
    heap->heap_size = 0;
}


Queue* initializeQueue(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    Queue* queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->data = malloc((size_t) capacity * sizeof(Elemento));
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }

    queue->FRONT = -1;
    queue->TAIL = -1;
    queue->capacity = capacity;
    queue->size = 0;

    return queue;
}


bool isEmpty(const Queue* queue) {
    return queue == NULL || queue->size == 0;
}


bool isFull(const Queue* queue) {
    return queue != NULL && queue->size == queue->capacity;
}


bool enqueue(Queue* queue, Elemento value) {
    if (queue == NULL || isFull(queue)) {
        return false;
    }

    if (isEmpty(queue)) {
        queue->FRONT = 0;
        queue->TAIL = 0;
    } else {
        queue->TAIL = (queue->TAIL + 1) % queue->capacity;
    }

    queue->data[queue->TAIL] = value;
    queue->size++;

    return true;
}


bool dequeue(Queue* queue, Elemento* value) {
    if (queue == NULL || value == NULL || isEmpty(queue)) {
        return false;
    }

    *value = queue->data[queue->FRONT];

    if (queue->size == 1) {
        queue->FRONT = -1;
        queue->TAIL = -1;
    } else {
        queue->FRONT = (queue->FRONT + 1) % queue->capacity;
    }

    queue->size--;

    return true;
}


void deleteQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }

    free(queue->data);
    free(queue);
}


void displayQueue(const Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue vuota.\n\n");
        return;
    }

    printf("Elementi nella queue:\n");
    int i = queue->FRONT;
    for (int count = 0; count < queue->size; count++) {
        printf("queue[%d] = ", count);
        printElemento(queue->data[i]);
        printf("\n");
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}


Queue* creaQueueDaVettore(Elemento** v, int n) {
    Queue* queue = initializeQueue(n);
    if (queue == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (!enqueue(queue, *v[i])) {
            deleteQueue(queue);
            return NULL;
        }
    }

    return queue;
}


int main(void) {
    Elemento vettore_input[N];
    Elemento** v1;
    MinHeap heap;
    Queue* queue;

    generaVettoreInput(vettore_input, N);

    v1 = creaVettoreDaInput(vettore_input, N);
    if (v1 == NULL) {
        return 1;
    }

    printf("Vettore prima dell'ordinamento:\n");
    printArray(v1, N);

    merge_sort(v1, 0, N - 1);

    printf("Vettore dopo l'ordinamento per v1:\n");
    printArray(v1, N);

    mergesort_strategy(v1, 0, N - 1, gt_v2);

    printf("Vettore dopo l'ordinamento per v2:\n");
    printArray(v1, N);

    int idx = binarySearchV2(v1, N, 51);
    if (idx != -1) {
        printf("Elemento con v2 = 51 trovato in posizione %d: { v1 = %d, v2 = %d, v3 = %d }\n\n",
               idx,
               v1[idx]->v1,
               v1[idx]->v2,
               v1[idx]->v3);
    } else {
        printf("Elemento con v2 = 51 non trovato\n\n");
    }

    mergesort_strategy(v1, 0, N - 1, gt_somma);

    printf("Vettore dopo l'ordinamento per v1 + v2 + v3:\n");
    printArray(v1, N);

    liberaVettore(v1, N);

    v1 = creaVettoreDaInput(vettore_input, N);
    if (v1 == NULL) {
        return 1;
    }

    printf("Vettore ricreato dai dati originali per queue e min heap:\n");
    printArray(v1, N);

    queue = creaQueueDaVettore(v1, N);
    if (queue == NULL) {
        liberaVettore(v1, N);
        return 1;
    }

    printf("Queue riempita da v1 non ordinato:\n");
    displayQueue(queue);

    printf("Svuotamento della queue:\n");
    Elemento estratto;
    while (dequeue(queue, &estratto)) {
        printf("dequeue -> ");
        printElemento(estratto);
        printf("\n");
    }
    printf("\n");
    displayQueue(queue);

    deleteQueue(queue);

    heap = creaMinHeapDaVettore(v1, N);
    if (heap.dati == NULL) {
        liberaVettore(v1, N);
        return 1;
    }

    printf("Min heap separato rispetto a v1:\n");
    printMinHeap(&heap);

    liberaMinHeap(&heap);
    liberaVettore(v1, N);

    return 0;
}

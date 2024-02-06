#include<stdio.h>
#include<stdlib.h>

void SCAN(int n, int head, int req[]) {
    int total_tracks = 200;  
    int direction = 1;  
    int seek_sequence[n + 1];
    int sorted_req[n];
    for (int i = 0; i < n; i++) {
    sorted_req[i] = req[i];
    }
    for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
    if (sorted_req[j] > sorted_req[j+1]) {
    int temp = sorted_req[j];
    sorted_req[j] = sorted_req[j+1];
    sorted_req[j+1] = temp;
    }
    }
    }

    int index;
    for (index = 0; index < n; index++) {
    if (sorted_req[index] >= head) {
    break;
    }
    }
    int left = index - 1;
    int right = index;
    int seek_count = 0;
    int current_track = head;
    while ((left >= 0) || (right < n)) {
        if (direction == 1) {
            if (right < n) {
                seek_sequence[seek_count++] = sorted_req[right];
                current_track = sorted_req[right];
                right++;
            } else {
                direction = -1;
            }
        } else if (direction == -1) {
            if (left >= 0) {
                seek_sequence[seek_count++] = sorted_req[left];
                current_track = sorted_req[left];
                left--;
            } else {
                direction = 1;
            }
        }
    } 
    printf("Seek Sequence: ");
    
    for (int i = 0; i < seek_count; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Seek Count: %d\n", seek_count);
}
int main() {
    int n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &head);
    SCAN(n, head, req);
    return 0;
}


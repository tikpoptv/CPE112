
// void Intersection(int subset1[], int size_subset1, int subset2[], int size_subset2) {
//     int intersectionSet[size_subset1 + size_subset2];
//     int intersectionSize = 0;

//     for (int i = 0; i < size_subset1; i++) {
//         for (int j = 0; j < size_subset2; j++) {
//             if (subset1[i] == subset2[j]) {
//                 intersectionSet[intersectionSize++] = subset1[i];
//                 break;
//             }
//         }
//     }
//     if (intersectionSize == 0) {
//         printf("empty\n");
//     } else {
//         for (int i = 0; i < intersectionSize; i++) {
//             printf("%d ", intersectionSet[i]);
//         }
//         printf("\n");
//     }
// }
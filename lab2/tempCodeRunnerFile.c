
// void deletion(int *input, int sizeset, int posi) {

//     int sizeset += 1;

//     int *temp = (int*)malloc(sizeset-1*sizeof(int));

//     for (int i = 0; i < sizeset-1; i++)
//     {
//         if (i<posi)
//         {
//             *(temp+i) = *(input+i);
//         }else
//         {
//             *(temp+i) = *(input+i+1);
//         }
//     }
//     for (int i = 0; i < sizeset-1; i++)
//     {
//         printf("%d ",*(temp+i));
//     }

//     free(temp);
// }
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/
public class Solution {
    public void rotate(int[][] matrix) {
        int row = 0;
        int row_end = matrix.length-1;
        int column = 0;
        int column_end = matrix[0].length-1;
        //int new_matrix[][] = new int[matrix.length][matrix[0].length];
        while(row<row_end && column<column_end){
            if(row==row_end+1 || column == column_end+1){
                break;
            }
            int temp[] = new int[column_end-column+1];
            int temp1[] = new int[column_end-column+1];
            int temp_cntr = 0;
            for(int i=row+1;i<row_end;i++){
                temp[temp_cntr++] = matrix[i][column_end];
                matrix[i][column_end] = matrix[row][i];
                
            }
            //row++;
            //int array_iter = row+1;
            temp_cntr = 0;
            for(int i=column_end-1;i>column;i--){
                temp1[temp_cntr] = matrix[row_end][i];
                matrix[row_end][i] = temp[temp_cntr++];
            }
            temp_cntr=0;
            for(int i=row_end-1;i>row;i--){
                temp[temp_cntr] = matrix[i][column];
                matrix[i][column] = temp1[temp_cntr++];
            }
            //array_iter = row_end-1;
            temp_cntr=0;
            for(int i=column+1;i<column_end;i++){
                matrix[row][i] = temp[temp_cntr++];
            }
            int temp_corner;
            temp_corner = matrix[row][column_end];
            matrix[row][column_end] = matrix[row][column];
            matrix[row][column] = matrix[row_end][column];
            matrix[row_end][column] = matrix[row_end][column_end];
            matrix[row_end][column_end] = temp_corner;
            //matrix[ro]
            row++;
            row_end--;
            column++;
            column_end--;
            
            
            
        }
    }
}
import java.util.Scanner;
import java.util.zip.CheckedOutputStream;

//题目三
//给定一组输入数据（从键盘输入），通过一种排序算法（如插入排序、选择
//排序、归并排序、冒泡排序、快速排序、堆排序等一种）排序后输出；再从
//键盘输入一个数据，通过二分查找算法，检索该数据是否在排序的数据中，
//若在请输出其索引号；若不存在，请给出提示。
public class Question_3 {
    public static void sort(int []arr){
        for (int i = 0; i < arr.length-1; i++) {
            boolean flag=true;
            for (int j = 0; j < arr.length-1-i; j++) {
                if (arr[j]>arr[j+1]) {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flag=false;
                }
            }
            if (flag) {
                break;
            }
        }
    }
    public static int search(int x,int []arr){
        int l=0,r=arr.length-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]>x)r=mid-1;
            else if(arr[mid]<x)l=mid+1;
            else return mid;
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入数组长度：");
        int n=sc.nextInt();
        int []arr=new int[n];
        System.out.println("请输入数组元素:");
        int x=0;
        for(int i=0;i<n;i++) {
            x = sc.nextInt();
            arr[i]=x;
        }
        sort(arr);
        System.out.println("请输入您想要查找的数字：");
        x = sc.nextInt();
        int f = search(x, arr);
        if (f != -1) System.out.println("(重复元素只显示其中一个的下标)该数字在数组中，下标为:" + f);
        else System.out.println("该数字不在数组中！");
    }
}

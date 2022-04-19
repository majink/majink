#include <stdio.h>
#include <string.h>
#include "product.h"

int main(void){
    Product s[20];
    int count = 0, menu,index=0;

    count = loadData(s);
    index = count;

    if(count >0)printf("=>파일 읽기 완료!\n");
    else printf("=>파일 없음!\n");
    while (1){

      
        menu = selectMenu();
        int check=0;
        if (menu == 0) break;
        else if (menu == 1){
           if(count>0)listProduct(s,index);
        }
        else if (menu == 2){
            count += addProduct(&s[index++]);
        }
        else if (menu == 3){
          int no = selectDataNo(s,index);
            if(no==0){
            printf("=> 취소됨!\n");
            continue;
              }
          check =  updateProduct(&s[no-1]);
        if(check==1)printf("=>수정됨!\n");          
        }
        else if (menu == 4){
          int no = selectDataNo(s,index);
            if(no==0){
            printf("=> 취소됨!\n");
            continue;
              }
          int del;
          printf("정말로 삭제하시겠습니까? (삭제 :1)");
          scanf("%d",&del);
          if(del==1){
            check =deleteProduct(&s[no-1]);
            if(check==1){
            printf("=>삭제됨!\n");
            count--;
              }
        }
        }
        else if(menu == 5){
          saveData(s, index);
        }
        else if(menu==6){
           searchProduct(s ,index);
        }
       else if(menu==7){
           searchDeliver(s ,index);
        }
        else if(menu==8){
           searchLocal(s ,index);
        }
       else break;
    }
    printf("종료됨!\n");
    return 0;
}

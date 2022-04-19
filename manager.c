#include <stdio.h>
#include <string.h>
#include "product.h"

int selectMenu(){
    int menu;
#ifdef DEBUG
    printf("DEBUGGING이 실행되었습니다.");
#endif


    printf("\n*** 각 지역의 특산물 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 제품 이름 검색\n");
    printf("7. 배송방법에 따른 제품 검색\n");
    printf("8. 원산지 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
  
    return menu;
}
int addProduct(Product *p){//관리하는 제품 종류 추가하는 함수
    printf("제품명은?");
    getchar();
    fgets(p->name , 100 , stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("제품 설명은(원산지)?");
    scanf("%s", p->explain);
    printf("제품 중량은?(숫자만 입력)");
    scanf("%d",&p->gram);
    printf("제품의 판매 가격은?");
    scanf("%d",&p->price);
    printf("배송 방법은? (1:새벽배송, 2:택배배송)");
    scanf("%d",&p->deliver);

return 1;  
  }
void listProduct(Product *p, int index){ //관리하는 제품의 리스트 출력하는 함수
    for(int i=0 ; i<index ; i++){
        if(p[i].price != -1){
            printf("%d번째 제품\n",i+1);
            readProduct(&p[i]);
        }
    }
}
void readProduct(Product *p){ //하나의 제품의 상세 설명을 출력하는 함수
    printf("제품명 : %s\n", p->name);
    printf("설명:%s\n",p->explain);
    printf("중량 : %d\n", p->gram);
    printf("가격 : %d\n",p->price);
    printf("배송 방법 :");
    if(p->deliver==1)printf("새벽배송\n");
    else printf("택배배송\n");
}
int selectDataNo(Product *p, int count){//수정 또는 삭제할 제품을 선택하게 하는 함수
    int no;
    listProduct(p, count);
    printf("번호는 (취소 : 0)?");
    scanf("%d",&no);
    return no;
}

int updateProduct(Product *p){//하나의 제품의 정보를 수정하는 함수
    printf("제품명은?");
    getchar();
    fgets(p->name , 100 , stdin);
    p->name[strlen(p->name)-1]='\0';
    printf("제품 설명은(원산지)?");
    scanf("%s", p->explain);
    printf("제품 중량은?");
    scanf("%d",&p->gram);
    printf("제품의 판매 가격은?");
    scanf("%d",&p->price);
    printf("배송 방법은? (1:새벽배송, 2:택배배송)");
    scanf("%d",&p->deliver);
    return 1;
}

int deleteProduct(Product *p){//하나의 제품을 삭제하는 함수
   return p->price = -1;
}

void saveData(Product *p, int count){//정보를 저장하는 함수
    FILE *fp;
    fp = fopen("product.txt", "w");
    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1)continue;
        fprintf(fp, "%s %s %d %d %d", p[i].name, p[i].explain, p[i].gram, p[i].price, p[i].deliver);
    }
    fclose(fp);
    printf("=>저장됨!\n");
}

int loadData(Product *p){//기존 파일의 정보를 읽어오는 함수
    int i=0;
    FILE *fp;
    fp = fopen("product.txt", "r");
    for(; i<20 ; i++){
        fscanf(fp , "%s" , p[i].name);
        fscanf(fp, "%s", p[i].explain);
        if(feof(fp))break;
        fscanf(fp, "%d", &p[i].gram);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%d", &p[i].deliver);
    }
return i;
}

void searchProduct(Product *p , int count){//제품의 이름을 검색하는 함수
    char search[20];
    int scnt=0;
    printf("검색할 제품명은?");
    scanf("%s",search);

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1)continue;
        if(strstr(p[i].name,search)){
            printf("%d번째 제품\n",i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchDeliver(Product *p, int count){//(num=>새벽배송:1,택배배송:2)
    int search;
    int scnt=0;
    printf("새벽배송 제품을 찾으신다면 1을, 택배배송 제품을 찾으신다면 2를 입력해주세요.");
    scanf("%d",&search);

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1)continue;
        if(p[i].deliver==search){
            printf("%d번째 제품\n", i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}
void searchLocal(Product *p,int count){//원산지를 검색하는 함수
    char search[20];
    int scnt=0;
    printf("검색할 원산지는?");
    scanf("%s",search);

    for(int i=0 ; i<count ; i++){
        if(p[i].price==-1)continue;
        if(strstr(p[i].explain,search)){
            printf("%d번째 제품\n",i+1);
            readProduct(&p[i]);
            scnt++;
        }
    }
    if(scnt==0)printf("=>검색된 데이터 없음!");
    printf("\n");
}

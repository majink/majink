typedef struct 
{
    char name[20];//제품명
    char explain[100];//설명
    int gram;//중량
    int price;//판매가격
    int deliver;//1:새벽배송/2:택배배송
}Product;

int addProduct(Product *p); //관리하는 제품 종류 추가하는 함수
void listProduct(Product *p, int index); //관리하는 제품의 리스트 출력하는 함수
void readProduct(Product *p); //하나의 제품의 상세 설명을 출력하는 함수
int selectDataNo(Product *p, int count);//수정 또는 삭제할 제품을 선택하게 하는 함수
int updateProduct(Product *p);//하나의 제품의 정보를 수정하는 함수
int deleteProduct(Product *p);//하나의 제품을 삭제하는 함수
void saveData(Product *p, int count); //정보를 저장하는 함수
int loadData(Product *p); //기존 파일의 정보를 읽어오는 함수

void searchProduct(Product *p , int count); //제품의 이름을 검색하는 함수
void searchDeliver(Product *p, int count); //새벽배송 or 택배배송되는 제품을 검색하는 함수(num=>새벽배송:1,택배배송:2)
void searchLocal(Product *p,int count);//원산지를 검색하는 함수
int selectMenu();


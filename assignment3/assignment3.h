#include <iostream>
#include <vector>

using namespace std;

class User {
    private:
        string name;
        string ssn;
        string id;
        string pw;

    public:
        User(string name, string ssn, string id, string pw); // UserList의 signup에서 인스턴스 생성

};

class UserList {
    private:
        vector<User*> userList; // 회원 목록
        string accountLoggedIn; // 현재 로그인된 회원 id

    public:
        UserList(); // 생성자
        
        // 1.1 회원가입
        void signup(string name, string ssn, string id, string pw);

        // 1.2 회원탈퇴
        /*
            usersList에서 삭제
            ? : 배열에서 어케 삭제함;;
            TODO: vector
        */
        void resign(string id);

        // 2.1 로그인
        /* 
            accountLoggedIn에 id 등록
        */
        void login(string id, string pw); 

        // 2.2 로그아웃
        void logout(string id); /* logIn = false */
};

class Seller {

    private:
        

    public:
        // 3.1 판매 의류 등록
        /* 
            sellingProducts 배열에 추가함 (vector로 넣어도 될듯 - C++에도 해시 자료구조 있으면 그걸로 선택)
        */
        void enrollSellingProduct(string name, string company, int price, int amount);

        // 3.2 등록 상품 조회
        void getSellingProducts();

        // 3.3 판매 완료 상품 조회
        /* 
            quantity == 0 인 상품들만 출력
        */
        void getSoldoutProducs(); 

        // 5.1 판매 상품 통계
        // ? 평점 없으면? -> 초기값은 0이라고 함
        void getSellingHistory();
};

class SellingProduct {
    private:
        string name;
        string company;
        string id;
        int price;
        int quantity;
        int reviewScore; // 초기값 0

    public:
        SellingProduct(string name, string company, int price, int quantity);
};

class SellingProductList{
    private:
        vector<SellingProduct *> sellingProductList; // 전체 판매 목록
    
    public:
        void getSellerProducts(string id); // 특정 판매자의 상품 조회
        void getSellingProduct(string name); // 특정 상품 조회
};

class Buyer { 
    private:
        string searchedProduct; // 4.1 상품 정보 검색 시 검색어 저장 (ptr로 할 수도 있을듯)
        vector<SellingProduct *> purchasedProductList; // 구매자가 구매한 상품 목록

    public:
        // asdxzdzxt4.1 상품 정보 검색
        void searchProducts(string name);

        // TODO: 검색한거 강제 구매?
        // 4.2 상품 구매
        void purchaseProduct(); // searchedItem에 있는 항목 count - 1

        // 4.3 상품 구매 내역 조회
        // ? 상품 구매가 일어날 때마다 해당 상품에 대한
        void getPurchaseHistory();

        // 4.4 상품 구매 만족도 평가
        void writeReview(string name, int score); // 추가할 때마다 평균 만족도 update
};

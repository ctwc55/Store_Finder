//함수의 정의를 위치
#include "storeinfo.h"

Node store[1000];
//200경영관 201중앙도서관  202쪽문엘리베이터  203학교정문  204혜화역4번출구  205올레사거리  206혜화역1번출구
//207호암관 208수선관 209경제관 210국제관
//쪽문 = 211, 정문 = 212, 대명거리 = 213, 소나무길 = 214, 대학로 = 215


//교내store(0~6) 소나무길store(7~39) 대명거리store(40~54, 108~118)
//쪽문store(55 - 72)  정문store(69 - 88, 103 - 107)  대학로store(89 - 102)


// type 식당 = 0, 약국 = 1, 편의점, 마트 = 2, 카페 = 3, 정점 = 4
// type_eat 식당X = 0 한식 = 1, 일식 = 2, 중식 = 3, 양식 = 4, 고기 = 5, 닭 = 6, 기타 = 7


//------------------------교내------------------------ -

//금잔디 식당
store[0].position = 200;
store[0].url = ”X”;
store[0].name = “금잔디식당”;
store[0].price = 5000;
store[0].type = 0;
store[0].type_eat = 7;
store[0].store_to_pos_dist = 0;
store[0].second_near = 209;
store[0].store_to_sec_dist = 46;

//맘스터치(금잔디)
store[1].position = 200;
store[1].url = "X";
store[1].name = "맘스터치(금잔디)";
store[1].price = 5000;
store[1].type = 0;
store[1].type_eat = 7;
store[1].store_to_pos_dist = 0;
store[1].second_near = 209;
store[1].store_to_sec_dist = 46;

//CU
store[2].position = 200;
store[2].url = ”X”;
store[2].name = ”CU”;
store[2].price = 0;
store[2].type = 2;
store[2].type_eat = 0;
store[2].store_to_pos_dist = 0;
store[2].second_near = 209;
store[2].store_to_sec_dist = 46;

//사랑방
store[3].position = 200;
store[3].url = ”X”;
store[3].name = ”사랑방”;
store[3].price = 3000;
store[3].type = 3;
store[3].type_eat = 0;
store[3].store_to_pos_dist = 0;
store[3].second_near = 209;
store[3].store_to_sec_dist = 46;

//은행골식당
store[4].position = 216;
store[4].url = ”X”;
store[4].name = ”은행골 식당”;
store[4].price = 5000;
store[4].type = 0;
store[4].type_eat = 7;
store[4].store_to_pos_dist = 0;
store[4].second_near = 210;
store[4].store_to_sec_dist = 121;

//도미노피자(은행골)
store[5].position = 216;
store[5].url = ”https://web.dominos.co.kr/main”;
store[5].name = ”도미노피자(은행골)”;
store[5].price = 10000;
store[5].type = 0;
store[5].type_eat = 4;
store[5].store_to_pos_dist = 0;
store[5].second_near = 210;
store[5].store_to_sec_dist = 121;

//서브웨이(은행골)
store[6].position = 216;
store[6].url = ”http://subway.co.kr/”;
store[6].name = ”서브웨이(은행골)”;
store[6].price = 8000;
store[6].type = 0;
store[6].type_eat = 7;
store[6].store_to_pos_dist = 0;
store[6].second_near = 210;
store[6].store_to_sec_dist = 121;

//------------------ - 소나무길----------------------

//명쭈삼
store[7].position = 214;
store[7].url = ”https://www.audwn3.com/”;
store[7].name = ”명쭈삼”;
store[7].price = 15000;
store[7].type = 0;
store[7].type_eat = 1;
store[7].store_to_pos_dist = 37;
store[7].second_near = 205;
store[7].store_to_sec_dist = 60;

//전설의 짬뽕
store[8].position = 214;
store[8].url = ”www.legendgo.co.kr”;
store[8].name = ”전설의 짬뽕”;
store[8].price = 10000;
store[8].type = 0;
store[8].type_eat = 3;
store[8].store_to_pos_dist = 31;
store[8].second_near = 205;
store[8].store_to_sec_dist = 77;

//돈돈정
store[9].position = 214;
store[9].url = ”X”;
store[9].name = ”돈돈정”;
store[9].price = 15000;
store[9].type = 0;
store[9].type_eat = 2;
store[9].store_to_pos_dist = 37;
store[9].second_near = 205;
store[9].store_to_sec_dist = 59;

//뎁짜이
store[10].position = 214;
store[10].url = ”http://www.instagram.com/dep_trai_korea”;
store[10].name = ”뎁짜이”;
store[10].price = 10000;
store[10].type = 0;
store[10].type_eat = 7;
store[10].store_to_pos_dist = 62;
store[10].second_near = 205;
store[10].store_to_sec_dist = 86;

//깔리
store[11].position = 214;
store[11].url = ”X”;
store[11].name = “깔리”;
store[11].price = 15000;
store[11].type = 0;
store[11].type_eat = 7;
store[11].store_to_pos_dist = 62;
store[11].second_near = 205;
store[11].store_to_sec_dist = 86;

//르아브르
store[12].position = 214;
store[12].url = ”http://instagram.com/cafe_lehavre”;
store[12].name = ”르아브르”;
store[12].price = 5000;
store[12].type = 3;
store[12].type_eat = 0;
store[12].store_to_pos_dist = 43;
store[12].second_near = 205;
store[12].store_to_sec_dist = 49;

//와인한잔
store[13].position = 214;
store[13].url = ”X”;
store[13].name = ”와인한잔”;
store[13].price = 15000;
store[13].type = 0;
store[13].type_eat = 4;
store[13].store_to_pos_dist = 84;
store[13].second_near = 205;
store[13].store_to_sec_dist = 90;

//현초밥
store[14].position = 214;
store[14].url = ”X”;
store[14].name = ”현초밥”;
store[14].price = 10000;
store[14].type = 0;
store[14].type_eat = 2;
store[14].store_to_pos_dist = 68;
store[14].second_near = 205;
store[14].store_to_sec_dist = 92;

//은행골
store[15].position = 214;
store[15].url = ”X”;
store[15].name = ”은행골”;
store[15].price = 15000;
store[15].type = 0;
store[15].type_eat = 2;
store[15].store_to_pos_dist = 138;
store[15].second_near = 205;
store[15].store_to_sec_dist = 162;

//카페 혜화동
store[16].position = 214;
store[16].url = ”X”;
store[16].name = ”카페 혜화동”;
store[16].price = 8000;
store[16].type = 3;
store[16].type_eat = 0;
store[16].store_to_pos_dist = 119;
store[16].second_near = 205;
store[16].store_to_sec_dist = 143;

//세븐일레븐 명륜카페점 
store[17].position = 214;
store[17].url = ”X”;
store[17].name = ”세븐일레븐 명륜카페점”;
store[17].price = 0;
store[17].type = 2;
store[17].type_eat = 0;
store[17].store_to_pos_dist = 122;
store[17].second_near = 205;
store[17].store_to_sec_dist = 146;

//정민온누리약국
store[18].position = 214;
store[18].url = ”X”;
store[18].name = ”정민온누리약국”;
store[18].price = 0;
store[18].type = 1;
store[18].type_eat = 0;
store[18].store_to_pos_dist = 122;
store[18].second_near = 205;
store[18].store_to_sec_dist = 146;

//창화당
store[19].position = 214;
store[19].url = ”http://www.chdang.com”;
store[19].name = ”창화당”;
store[19].price = 10000;
store[19].type = 0;
store[19].type_eat = 1;
store[19].store_to_pos_dist = 120;
store[19].second_near = 205;
store[19].store_to_sec_dist = 144;

//멘야산다이메
store[20].position = 214;
store[20].url = ”http://www.menyasandaime.co.kr/”;
store[20].name = ”멘야산다이메”;
store[20].price = 8000;
store[20].type = 0;
store[20].type_eat = 2;
store[20].store_to_pos_dist = 142;
store[20].second_near = 205;
store[20].store_to_sec_dist = 166;

//라미스
store[21].position = 214;
store[21].url = ”X”;
store[21].name = ”라미스”;
store[21].price = 5000;
store[21].type = 3;
store[21].type_eat = 0;
store[21].store_to_pos_dist = 118;
store[21].second_near = 205;
store[21].store_to_sec_dist = 142;

//부탄츄
store[22].position = 214;
store[22].url = ”http://butanchu.com”;
store[22].name = ”부탄츄”;
store[22].price = 10000;
store[22].type = 0;
store[22].type_eat = 2;
store[22].store_to_pos_dist = 192;
store[22].second_near = 205;
store[22].store_to_sec_dist = 216;

//서양집
store[23].position = 214;
store[23].url = ”https://www.instagram.com/seoyangzip/”;
store[23].name = ”서양집”;
store[23].price = 15000;
store[23].type = 0;
store[23].type_eat = 4;
store[23].store_to_pos_dist = 192;
store[23].second_near = 205;
store[23].store_to_sec_dist = 216;

//엽기떡볶이
store[24].position = 214;
store[24].url = ”http://www.yupdduk.com/”;
store[24].name = ”엽기떡볶이”;
store[24].price = 8000;
store[24].type = 0;
store[24].type_eat = 7;
store[24].store_to_pos_dist = 99;
store[24].second_near = 205;
store[24].store_to_sec_dist = 123;

//싸다김밥
store[25].position = 214;
store[25].url = ”X”;
store[25].name = ”싸다김밥”;
store[25].price = 8000;
store[25].type = 0;
store[25].type_eat = 1;
store[25].store_to_pos_dist = 95;
store[25].second_near = 205;
store[25].store_to_sec_dist = 101;

//캑터스
store[26].position = 214;
store[26].url = ”X”;
store[26].name = ”캑터스”;
store[26].price = 15000;
store[26].type = 0;
store[26].type_eat = 7;
store[26].store_to_pos_dist = 77;
store[26].second_near = 205;
store[26].store_to_sec_dist = 62;

//봉추찜닭
store[27].position = 214;
store[27].url = ”http://www.bongchu.com”;
store[27].name = ”봉추찜닭”;
store[27].price = 15000;
store[27].type = 0;
store[27].type_eat = 6;
store[27].store_to_pos_dist = 124;
store[27].second_near = 205;
store[27].store_to_sec_dist = 148;

//교촌치킨
store[28].position = 214;
store[28].url = ”http://www.kyochon.com/”;
store[28].name = ”교촌치킨”;
store[28].price = 20000;
store[28].type = 0;
store[28].type_eat = 6;
store[28].store_to_pos_dist = 134;
store[28].second_near = 205;
store[28].store_to_sec_dist = 158;

//호호식당
store[29].position = 214;
store[29].url = ”https://www.instagram.com/hohosikdang/”;
store[29].name = ”호호식당”;
store[29].price = 15000;
store[29].type = 0;
store[29].type_eat = 2;
store[29].store_to_pos_dist = 134;
store[29].second_near = 205;
store[29].store_to_sec_dist = 158;

//정돈
store[30].position = 214;
store[30].url = ”https://blog.naver.com/jungdon0916”;
store[30].name = ”정돈”;
store[30].price = 15000;
store[30].type = 0;
store[30].type_eat = 2;
store[30].store_to_pos_dist = 239;
store[30].second_near = 205;
store[30].store_to_sec_dist = 263;

//GS25 명륜스타점
store[31].position = 214;
store[31].url = ”X”;
store[31].name = ”GS25 명륜스타점”;
store[31].price = 0;
store[31].type = 2;
store[31].type_eat = 0;
store[31].store_to_pos_dist = 174;
store[31].second_near = 205;
store[31].store_to_sec_dist = 198;

//메밀향그집
store[32].position = 214;
store[32].url = ”https://www.instagram.com/memilhyang”;
store[32].name = ”메밀향그집”;
store[32].price = 15000;
store[32].type = 0;
store[32].type_eat = 6;
store[32].store_to_pos_dist = 183;
store[32].second_near = 205;
store[32].store_to_sec_dist = 207;

//쪼리닭
store[33].position = 214;
store[33].url = ”X”;
store[33].name = ”쪼리닭”;
store[33].price = 15000;
store[33].type = 0;
store[33].type_eat = 6;
store[33].store_to_pos_dist = 182;
store[33].second_near = 205;
store[33].store_to_sec_dist = 206;

//버거파크
store[34].position = 214;
store[34].url = ”http://www.burgerpark.co.kr/”;
store[34].name = ”버거파크”;
store[34].price = 15000;
store[34].type = 0;
store[34].type_eat = 4;
store[34].store_to_pos_dist = 225;
store[34].second_near = 205;
store[34].store_to_sec_dist = 249;

//커핀그루나루
store[35].position = 214;
store[35].url = ”X”;
store[35].name = ”커핀그루나루”;
store[35].price = 5000;
store[35].type = 3;
store[35].type_eat = 0;
store[35].store_to_pos_dist = 238;
store[35].second_near = 205;
store[35].store_to_sec_dist = 262;

//CU 대학로광장점
store[36].position = 214;
store[36].url = ”X”;
store[36].name = ”CU 대학로광장점”;
store[36].price = 0;
store[36].type = 2;
store[36].type_eat = 0;
store[36].store_to_pos_dist = 293;
store[36].second_near = 205;
store[36].store_to_sec_dist = 317;

//새마을식당
store[37].position = 214;
store[37].url = ”http://newmaul.com”;
store[37].name = ”새마을식당”;
store[37].price = 10000;
store[37].type = 0;
store[37].type_eat = 5;
store[37].store_to_pos_dist = 240;
store[37].second_near = 205;
store[37].store_to_sec_dist = 264;

//파랑새약국
store[38].position = 214;
store[38].url = ”X”;
store[38].name = ”파랑새약국”;
store[38].price = 0;
store[38].type = 1;
store[38].type_eat = 0;
store[38].store_to_pos_dist = 294;
store[38].second_near = 205;
store[38].store_to_sec_dist = 318;

//서울위드팜약국
store[39].position = 214;
store[39].url = ”X”;
store[39].name = ”서울위드팜약국”;
store[39].price = 0;
store[39].type = 1;
store[39].type_eat = 0;
store[39].store_to_pos_dist = 307;
store[39].second_near = 205;
store[39].store_to_sec_dist = 331;

---------------------- - 대명거리----------------------

//김가네
store[40].position = 213;
store[40].url = ”http://www.gimgane.co.kr”;
store[40].name = ”김가네”;
store[40].price = 8000;
store[40].type = 0;
store[40].type_eat = 1;
store[40].store_to_pos_dist = 0;
store[40].second_near = 205;
store[40].store_to_sec_dist = 45;

//스시사소우
store[41].position = 213;
store[41].url = ”X”;
store[41].name = ”스시사소우”;
store[41].price = 15000;
store[41].type = 0;
store[41].type_eat = 2;
store[41].store_to_pos_dist = 0;
store[41].second_near = 205;
store[41].store_to_sec_dist = 45;

//킹스빈커피
store[42].position = 213;
store[42].url = ”X”;
store[42].name = ”킹스빈커피”;
store[42].price = 5000;
store[42].type = 3;
store[42].type_eat = 0;
store[42].store_to_pos_dist = 0;
store[42].second_near = 205;
store[42].store_to_sec_dist = 12;

//내찜닭
store[43].position = 213;
store[43].url = ”X”;
store[43].name = ”내찜닭”;
store[43].price = 15000;
store[43].type = 0;
store[43].type_eat = 6;
store[43].store_to_pos_dist = 14;
store[43].second_near = 205;
store[43].store_to_sec_dist = 41;

//놀부부대찌개
store[44].position = 213;
store[44].url = ”https://www.nolboo.co.kr/pages/business/brand_boodae.asp”;
store[44].name = ”놀부부대찌개”;
store[44].price = 10000;
store[44].type = 0;
store[44].type_eat = 1;
store[44].store_to_pos_dist = 33;
store[44].second_near = 205;
store[44].store_to_sec_dist = 60;

//프루츠
store[45].position = 213;
store[45].url = ”X”;
store[45].name = ”프루츠”;
store[45].price = 10000;
store[45].type = 0;
store[45].type_eat = 7;
store[45].store_to_pos_dist = 36;
store[45].second_near = 205;
store[45].store_to_sec_dist = 63;

//식탁의목적
store[46].position = 213;
store[46].url = ”X”;
store[46].name = ”식탁의목적”;
store[46].price = 8000;
store[46].type = 0;
store[46].type_eat = 1;
store[46].store_to_pos_dist = 64;
store[46].second_near = 205;
store[46].store_to_sec_dist = 120;

//플라잉볼익스프레스
store[47].position = 213;
store[47].url = ”http://flyingbowlexpress.com/”;
store[47].name = ”플라잉볼익스프레스”;
store[47].price = 8000;
store[47].type = 0;
store[47].type_eat = 4;
store[47].store_to_pos_dist = 71;
store[47].second_near = 205;
store[47].store_to_sec_dist = 146;

//산쪼메
store[48].position = 213;
store[48].url = ”http://sanchome.co.kr”;
store[48].name = ”산쪼메”;
store[48].price = 8000;
store[48].type = 0;
store[48].type_eat = 2;
store[48].store_to_pos_dist = 71;
store[48].second_near = 205;
store[48].store_to_sec_dist = 146;

//육회한연어
store[49].position = 213;
store[49].url = ”http://www.happysalmon.co.kr/”;
store[49].name = ”육회한연어”;
store[49].price = 15000;
store[49].type = 0;
store[49].type_eat = 5;
store[49].store_to_pos_dist = 71;
store[49].second_near = 205;
store[49].store_to_sec_dist = 113;

//혜화수약국
store[50].position = 213;
store[50].url = ”X”;
store[50].name = ”혜화수약국”;
store[50].price = 0;
store[50].type = 1;
store[50].type_eat = 0;
store[50].store_to_pos_dist = 77;
store[50].second_near = 204;
store[50].store_to_sec_dist = 139;

//도쿄스테이크
store[51].position = 213;
store[51].url = ”http://tokyosteak.co.kr”;
store[51].name = ”도쿄스테이크”;
store[51].price = 10000;
store[51].type = 0;
store[51].type_eat = 2;
store[51].store_to_pos_dist = 95;
store[51].second_near = 204;
store[51].store_to_sec_dist = 145;

//하루가
store[52].position = 213;
store[52].url = ”X”;
store[52].name = ”하루가”;
store[52].price = 10000;
store[52].type = 0;
store[52].type_eat = 7;
store[52].store_to_pos_dist = 105;
store[52].second_near = 205;
store[52].store_to_sec_dist = 132;

//혼카츠
store[53].position = 213;
store[53].url = ”X”;
store[53].name = ”혼카츠”;
store[53].price = 10000;
store[53].type = 0;
store[53].type_eat = 2;
store[53].store_to_pos_dist = 113;
store[53].second_near = 204;
store[53].store_to_sec_dist = 103;

//엉터리생고기
store[54].position = 213;
store[54].url = ”X”;
store[54].name = ”엉터리생고기”;
store[54].price = 10000;
store[54].type = 0;
store[54].type_eat = 5;
store[54].store_to_pos_dist = 124;
store[54].second_near = 204;
store[54].store_to_sec_dist = 93;

//홍콩반점
store[108].position = 213;
store[108].url = ”http://www.theborn.co.kr/theborn_brand/zzambbong”;
store[108].name = ”홍콩반점”;
store[108].price = 5000;
store[108].type = 0;
store[108].type_eat = 3;
store[108].store_to_pos_dist = 126;
store[108].second_near = 204;
store[108].store_to_sec_dist = 90;

//서피동파
store[109].position = 213;
store[109].url = ”X”;
store[109].name = ”서피동파”;
store[109].price = 10000;
store[109].type = 0;
store[109].type_eat = 7;
store[109].store_to_pos_dist = 132;
store[109].second_near = 204;
store[109].store_to_sec_dist = 173;

//CU대학로2호점
store[110].position = 213;
store[110].url = ”X”;
store[110].name = ”CU대학로2호점”;
store[110].price = 0;
store[110].type = 2;
store[110].type_eat = 0;
store[110].store_to_pos_dist = 135;
store[110].second_near = 204;
store[110].store_to_sec_dist = 99;

//맘스터치
store[111].position = 213;
store[111].url = ”http://www.momstouch.co.kr”;
store[111].name = ”맘스터치”;
store[111].price = 8000;
store[111].type = 0;
store[111].type_eat = 7;
store[111].store_to_pos_dist = 139;
store[111].second_near = 204;
store[111].store_to_sec_dist = 103;

//마녀주방
store[112].position = 213;
store[112].url = ”https://witchskitchen.co.kr”;
store[112].name = ”마녀주방”;
store[112].price = 20000;
store[112].type = 0;
store[112].type_eat = 4;
store[112].store_to_pos_dist = 151;
store[112].second_near = 204;
store[112].store_to_sec_dist = 85;

//통큰갈비
store[113].position = 213;
store[113].url = ”http://www.통큰갈비.com”;
store[113].name = ”통큰갈비”;
store[113].price = 12000;
store[113].type = 0;
store[113].type_eat = 5;
store[113].store_to_pos_dist = 180;
store[113].second_near = 204;
store[113].store_to_sec_dist = 114;

//꼬꼬아찌
store[114].position = 213;
store[114].url = ”X”;
store[114].name = ”꼬꼬아찌”;
store[114].price = 20000;
store[114].type = 0;
store[114].type_eat = 6;
store[114].store_to_pos_dist = 181;
store[114].second_near = 204;
store[114].store_to_sec_dist = 83;

//할리스커피
store[115].position = 213;
store[115].url = ”http://www.hollys.co.kr”;
store[115].name = ”할리스커피”;
store[115].price = 5000;
store[115].type = 3;
store[115].type_eat = 0;
store[115].store_to_pos_dist = 196;
store[115].second_near = 204;
store[115].store_to_sec_dist = 21;

//GS25혜화대명점
store[116].position = 213;
store[116].url = ”X”;
store[116].name = ”GS25혜화대명점”;
store[116].price = 0;
store[116].type = 2;
store[116].type_eat = 0;
store[116].store_to_pos_dist = 306;
store[116].second_near = 204;
store[116].store_to_sec_dist = 77;

//노랑통닭
store[117].position = 213;
store[117].url = ”https://norangtongdak.co.kr/”;
store[117].name = ”노랑통닭”;
store[117].price = 15000;
store[117].type = 0;
store[117].type_eat = 6;
store[117].store_to_pos_dist = 308;
store[117].second_near = 204;
store[117].store_to_sec_dist = 84;

//동네아저씨치킨
store[118].position = 213;
store[118].url = ”X”;
store[118].name = ”동네아저씨치킨”;
store[118].price = 25000;
store[118].type = 0;
store[118].type_eat = 6;
store[118].store_to_pos_dist = 316;
store[118].second_near = 204;
store[118].store_to_sec_dist = 92;

-------------------- - 쪽문------------------------------ -
store[57].position = 211;
store[57].url = ”X”;
store[57].name = ”밥은”;
store[57].price = 5000;
store[57].type = 0;
store[57].type_eat = 1;
store[57].store_to_pos_dist = 89;
store[57].second_near = 200;
store[57].store_to_sec_dist = 475;

store[56].position = 211;
store[56].url = ”X”;
store[56].name = ”후쿠후쿠”;
store[56].price = 8000;
store[56].type = 0;
store[56].type_eat = 2;
store[56].store_to_pos_dist = 90;
store[56].second_near = 200;
store[56].store_to_sec_dist = 476;

store[66].position = 211;
store[66].url = ”X”;
store[66].name = ”천하제일탕수육”;
store[66].price = 5000;
store[66].type = 0;
store[66].type_eat = 7;
store[66].store_to_pos_dist = 182;
store[66].second_near = 201;
store[66].store_to_sec_dist = 609;

store[55].position = 211;
store[55].url = ”X”;
store[55].name = ”후라이팬”;
store[55].price = 8000;
store[55].type = 0;
store[55].type_eat = 7;
store[55].store_to_pos_dist = 40;
store[55].second_near = 200;
store[55].store_to_sec_dist = 426;

store[58].position = 211;
store[58].url = ”X”;
store[58].name = ”쇼타돈부리”;
store[58].price = 8000;
store[58].type = 0;
store[58].type_eat = 2;
store[58].store_to_pos_dist = 122;
store[58].second_near = 200;
store[58].store_to_sec_dist = 505;


store[59].position = 211;
store[59].url = ”X”;
store[59].name = ”청춘직화”;
store[59].price = 8000;
store[59].type = 0;
store[59].type_eat = 1;
store[59].store_to_pos_dist = 118;
store[59].second_near = 200;
store[59].store_to_sec_dist = 501;

store[61].position = 211;
store[61].url = ”X”;
store[61].name = ”우보장”;
store[61].price = 8000;
store[61].type = 0;
store[61].type_eat = 3;
store[61].store_to_pos_dist = 240;
store[61].second_near = 201;
store[61].store_to_sec_dist = 661;

store[60].position = 211;
store[60].url = ”X”;
store[60].name = ”서퍼피자”;
store[60].price = 10000;
store[60].type = 0;
store[60].type_eat = 4;
store[60].store_to_pos_dist = 86;
store[60].second_near = 200;
store[60].store_to_sec_dist = 469;

store[62].position = 211;
store[62].url = ”www.bongousse.net / main.aspx”;
store[62].name = ”봉구스밥버거”;
store[62].price = 5000;
store[62].type = 0;
store[62].type_eat = 1;
store[62].store_to_pos_dist = 150;
store[62].second_near = 201;
store[62].store_to_sec_dist = 654;

store[64].position = 211;
store[64].url = ”X”;
store[64].name = ”더닭”;
store[64].price = 8000;
store[64].type = 0;
store[64].type_eat = 6;
store[64].store_to_pos_dist = 223;
store[64].second_near = 201;
store[64].store_to_sec_dist = 644;

store[63].position = 211;
store[63].url = ”X”;
store[63].name = ”몬스터부리또”;
store[63].price = 5000;
store[63].type = 0;
store[63].type_eat = 7;
store[63].store_to_pos_dist = 91;
store[63].second_near = 200;
store[63].store_to_sec_dist = 474;

store[65].position = 211;
store[65].url = ”X”;
store[65].name = ”돈앤까”;
store[65].price = 8000;
store[65].type = 0;
store[65].type_eat = 2;
store[65].store_to_pos_dist = 99;
store[65].second_near = 200;
store[65].store_to_sec_dist = 483;

store[71].position = 211;
store[71].url = ”https://www.facebook.com/koffisix”;
store[71].name = ”쥬스식스”;
store[71].price = 5000;
store[71].type = 3;
store[71].type_eat = 0;
store[71].store_to_pos_dist = 139;
store[71].second_near = 201;
store[71].store_to_sec_dist = 560;

store[70].position = 211;
store[70].url = ”https://www.emart24.co.kr”;
store[70].name = ”이마트24편의점”;
store[70].price = 0;
store[70].type = 2;
store[70].type_eat = 0;
store[70].store_to_pos_dist = 120;
store[70].second_near = 200;
store[70].store_to_sec_dist = 502;

store[72].position = 211;
store[72].url = ”gs25.gsretail.com”;
store[72].name = ”GS25명륜성대점”;
store[72].price = 0;
store[72].type = 2;
store[72].type_eat = 0;
store[72].store_to_pos_dist = 298;
store[72].second_near = 203;
store[72].store_to_sec_dist = 367;

store[69].position = 211;
store[69].url = ”X”;
store[69].name = ”탑할인마트”;
store[69].price = 0;
store[69].type = 2;
store[69].type_eat = 0;
store[69].store_to_pos_dist = 253;
store[69].second_near = 203;
store[69].store_to_sec_dist = 401;

store[67].position = 211;
store[67].url = ”X”;
store[67].name = ”보성약국”;
store[67].price = 0;
store[67].type = 1;
store[67].type_eat = 0;
store[67].store_to_pos_dist = 182;
store[67].second_near = 201;
store[67].store_to_sec_dist = 565;

store[68].position = 211;
store[68].url = ”X”;
store[68].name = ”명륜시장약국”;
store[68].price = 0;
store[68].type = 1;
store[68].type_eat = 0;
store[68].store_to_pos_dist = 320;
store[68].second_near = 203;
store[68].store_to_sec_dist = 374;




----------------정문-------------------------------------- -
store[87].position = 212;
store[87].url = ”www.cknia.com”;
store[87].name = ”치킨매니아”;
store[87].price = 15000;
store[87].type = 0;
store[87].type_eat = 6;
store[87].store_to_pos_dist = 132;
store[87].second_near = 202;
store[87].store_to_sec_dist = 536;

store[88].position = 212;
store[88].url = ”X”;
store[88].name = ”명쭈3”;
store[88].price = 15000;
store[88].type = 0;
store[88].type_eat = 1;
store[88].store_to_pos_dist = 377;
store[88].second_near = 202;
store[88].store_to_sec_dist = 947;

store[74].position = 212;
store[74].url = ”X”;
store[74].name = ”홍곱창”;
store[74].price = 15000;
store[74].type = 0;
store[74].type_eat = 5;
store[74].store_to_pos_dist = 137;
store[74].second_near = 205;
store[74].store_to_sec_dist = 236;

store[104].position = 212;
store[104].url = ”sinjeon.co.kr”;
store[104].name = ”신전떡볶이”;
store[104].price = 5000;
store[104].type = 0;
store[104].type_eat = 7;
store[104].store_to_pos_dist = 116;
store[104].second_near = 205;
store[104].store_to_sec_dist = 169;

store[73].position = 212;
store[73].url = ”X”;
store[73].name = ”포보”;
store[73].price = 8000;
store[73].type = 0;
store[73].type_eat = 7;
store[73].store_to_pos_dist = 265;
store[73].second_near = 205;
store[73].store_to_sec_dist = 34;

store[80].position = 212;
store[80].url = ”X”;
store[80].name = ”화로상회”;
store[80].price = 15000;
store[80].type = 0;
store[80].type_eat = 5;
store[80].store_to_pos_dist = 134;
store[80].second_near = 205;
store[80].store_to_sec_dist = 206;

store[78].position = 212;
store[78].url = ”X”;
store[78].name = ”692고기포차”;
store[78].price = 20000;
store[78].type = 0;
store[78].type_eat = 5;
store[78].store_to_pos_dist = 202;
store[78].second_near = 205;
store[78].store_to_sec_dist = 132;

store[77].position = 212;
store[77].url = ”http://www.ssaum.co.kr/”;
store[77].name = ”싸움의고수”;
store[77].price = 10000;
store[77].type = 0;
store[77].type_eat = 5;
store[77].store_to_pos_dist = 116;
store[77].second_near = 205;
store[77].store_to_sec_dist = 169;

store[107].position = 212;
store[107].url = ”www.mcdonalds.co.kr”;
store[107].name = ”맥도날드”;
store[107].price = 8000;
store[107].type = 0;
store[107].type_eat = 7;
store[107].store_to_pos_dist = 205;
store[107].second_near = 314;
store[107].store_to_sec_dist = 48;

store[106].position = 212;
store[106].url = ”pizzaschool.net”;
store[106].name = ”피자스쿨”;
store[106].price = 8000;
store[106].type = 0;
store[106].type_eat = 4;
store[106].store_to_pos_dist = 143;
store[106].second_near = 205;
store[106].store_to_sec_dist = 156;

store[103].position = 212;
store[103].url = ”X”;
store[103].name = ”나누미”;
store[103].price = 5000;
store[103].type = 0;
store[103].type_eat = 1;
store[103].store_to_pos_dist = 179;
store[103].second_near = 205;
store[103].store_to_sec_dist = 94;

store[85].position = 212;
store[85].url = ”X”;
store[85].name = ”명륜왕만두”;
store[85].price = 5000;
store[85].type = 0;
store[85].type_eat = 7;
store[85].store_to_pos_dist = 257;
store[85].second_near = 205;
store[85].store_to_sec_dist = 54;

store[86].position = 212;
store[86].url = ”http://milsup.co.kr/”;
store[86].name = ”밀숲”;
store[86].price = 8000;
store[86].type = 0;
store[86].type_eat = 1;
store[86].store_to_pos_dist = 293;
store[86].second_near = 205;
store[86].store_to_sec_dist = 27;

store[81].position = 212;
store[81].url = ”X”;
store[81].name = ”기꾸스시”;
store[81].price = 15000;
store[81].type = 0;
store[81].type_eat = 2;
store[81].store_to_pos_dist = 265;
store[81].second_near = 205;
store[81].store_to_sec_dist = 34;

store[105].position = 212;
store[105].url = ”X”;
store[105].name = ”천향록”;
store[105].price = 15000;
store[105].type = 0;
store[105].type_eat = 3;
store[105].store_to_pos_dist = 177;
store[105].second_near = 205;
store[105].store_to_sec_dist = 122;

store[82].position = 212;
store[82].url = ”http://www.ddingddong.co.kr/”;
store[82].name = ”띵똥와플”;
store[82].price = 5000;
store[82].type = 3;
store[82].type_eat = 0;
store[82].store_to_pos_dist = 181;
store[82].second_near = 205;
store[82].store_to_sec_dist = 92;


store[84].position = 212;
store[84].url = ”ediya.com”;
store[84].name = ”이디야”;
store[84].price = 5000;
store[84].type = 3;
store[84].type_eat = 0;
store[84].store_to_pos_dist = 237;
store[84].second_near = 205;
store[84].store_to_sec_dist = 86;

store[83].position = 212;
store[83].url = ”www.tomntoms.com”;
store[83].name = ”탐앤탐스”;
store[83].price = 5000;
store[83].type = 3;
store[83].type_eat = 0;
store[83].store_to_pos_dist = 339;
store[83].second_near = 205;
store[83].store_to_sec_dist = 67;

store[76].position = 212;
store[76].url = ”www.emart24.co.kr”;
store[76].name = ”이마트24”;
store[76].price = 0;
store[76].type = 2;
store[76].type_eat = 0;
store[76].store_to_pos_dist = 175;
store[76].second_near = 205;
store[76].store_to_sec_dist = 116;

store[75].position = 212;
store[75].url = ”www.7 - eleven.co.kr”;
store[75].name = ”세븐일레븐성대점”;
store[75].price = 0;
store[75].type = 2;
store[75].type_eat = 0;
store[75].store_to_pos_dist = 123;
store[75].second_near = 205;
store[75].store_to_sec_dist = 207;

store[79].position = 212;
store[79].url = ”gs25.gsretail.com”;
store[79].name = ”GS25성대입구점”;
store[79].price = 0;
store[79].type = 2;
store[79].type_eat = 0;
store[79].store_to_pos_dist = 265;
store[79].second_near = 205;
store[79].store_to_sec_dist = 8;


---------------------- - 대학로----------------------------

store[89].position = 215;
store[89].url = ”http://abiko.kr/”;
store[89].name = ”아비꼬카레”;
store[89].price = 10000;
store[89].type = 0;
store[89].type_eat = 2;
store[89].store_to_pos_dist = 177;
store[89].second_near = 204;
store[89].store_to_sec_dist = 291;

store[90].position = 215;
store[90].url = ”http://www.cocoichibanya.co.kr/”;
store[90].name = ”코코이찌방야”;
store[90].price = 10000;
store[90].type = 0;
store[90].type_eat = 2;
store[90].store_to_pos_dist = 110;
store[90].second_near = 204;
store[90].store_to_sec_dist = 198;

store[92].position = 215;
store[92].url = ”https://www.facebook.com/daepochicken”;
store[92].name = ”대포찜닭”;
store[92].price = 15000;
store[92].type = 0;
store[92].type_eat = 6;
store[92].store_to_pos_dist = 303;
store[92].second_near = 204;
store[92].store_to_sec_dist = 383;

store[98].position = 215;
store[98].url = ” http ://mpizzeriao.fordining.kr/”;
store[98].name = ”핏제리아오”;
store[98].price = 20000;
store[98].type = 0;
store[98].type_eat = 4;
store[98].store_to_pos_dist = 516;
store[98].second_near = 204;
store[98].store_to_sec_dist = 633;

store[91].position = 215;
store[91].url = ”X”;
store[91].name = ”낙산가든”;
store[91].price = 20000;
store[91].type = 0;
store[91].type_eat = 5;
store[91].store_to_pos_dist = 49;
store[91].second_near = 204;
store[91].store_to_sec_dist = 172;

store[101].position = 215;
store[101].url = ”X”;
store[101].name = ”리얼시카고피자”;
store[101].price = 20000;
store[101].type = 0;
store[101].type_eat = 4;
store[101].store_to_pos_dist = 235;
store[101].second_near = 204;
store[101].store_to_sec_dist = 352;

store[100].position = 215;
store[100].url = ”https://www.tokkijung.co.kr/”;
store[100].name = ”토끼정”;
store[100].price = 15000;
store[100].type = 0;
store[100].type_eat = 7;
store[100].store_to_pos_dist = 454;
store[100].second_near = 204;
store[100].store_to_sec_dist = 571;

store[97].position = 215;
store[97].url = ”X”;
store[97].name = ”돌쇠아저씨”;
store[97].price = 10000;
store[97].type = 0;
store[97].type_eat = 7;
store[97].store_to_pos_dist = 113;
store[97].second_near = 204;
store[97].store_to_sec_dist = 176;

store[99].position = 215;
store[99].url = ”https://www.kfckorea.com/”;
store[99].name = ”KFC”;
store[99].price = 8000;
store[99].type = 0;
store[99].type_eat = 7;
store[99].store_to_pos_dist = 175;
store[99].second_near = 204;
store[99].store_to_sec_dist = 293;

store[95].position = 215;
store[95].url = ”http://www.emoikorea.com/”;
store[95].name = ”에머이”;
store[95].price = 10000;
store[95].type = 0;
store[95].type_eat = 7;
store[95].store_to_pos_dist = 314;
store[95].second_near = 204;
store[95].store_to_sec_dist = 431;

store[96].position = 215;
store[96].url = ”http://www.nipongnaepong.co.kr/”;
store[96].name = ”니뽕내뽕”;
store[96].price = 10000;
store[96].type = 0;
store[96].type_eat = 4;
store[96].store_to_pos_dist = 409;
store[96].second_near = 204;
store[96].store_to_sec_dist = 492;

store[102].position = 215;
store[102].url = ”sulbing.com”;
store[102].name = ”설빙”;
store[102].price = 5000;
store[102].type = 3;
store[102].type_eat = 0;
store[102].store_to_pos_dist = 178;
store[102].second_near = 204;
store[102].store_to_sec_dist = 296;

store[94].position = 215;
store[94].url = ”X”;
store[94].name = ”하트약국”;
store[94].price = 0;
store[94].type = 1;
store[94].type_eat = 0;
store[94].store_to_pos_dist = 72;
store[94].second_near = 204;
store[94].store_to_sec_dist = 190;

store[93].position = 215;
store[93].url = ”cu.bgfretail.com”;
store[93].name = ”CU종로동숭동점”;
store[93].price = 0;
store[93].type = 2;
store[93].type_eat = 0;
store[93].store_to_pos_dist = 116;
store[93].second_near = 204;
store[93].store_to_sec_dist = 234;

store[200].position = 200;
store[200].url = ”X”;
store[200].name = ”경영관”;
store[200].price = 0;
store[200].type = 4;
store[200].type_eat = 0;

store[201].position = 201;
store[201].url = ”X”;
store[201].name = ”중앙도서관”;
store[201].price = 0;
store[201].type = 4;
store[201].type_eat = 0;

store[202].position = 202;
store[202].url = ”X”;
store[202].name = ”쪽문엘리베이터”;
store[202].price = 0;
store[202].type = 4;
store[202].type_eat = 0;

store[203].position = 203;
store[203].url = ”X”;
store[203].name = ”학교정문”;
store[203].price = 0;
store[203].type = 4;
store[203].type_eat = 0;

store[204].position = 204;
store[204].url = ”X”;
store[204].name = ”혜화역4번출구”;
store[204].price = 0;
store[204].type = 4;
store[204].type_eat = 0;

store[205].position = 205;
store[205].url = ”X”;
store[205].name = ”올레사거리”;
store[205].price = 0;
store[205].type = 4;
store[205].type_eat = 0;

store[206].position = 206;
store[206].url = ”X”;
store[206].name = ”혜화역1번출구”;
store[206].price = 0;
store[206].type = 4;
store[206].type_eat = 0;

store[207].position = 207;
store[207].url = ”X”;
store[207].name = ”호암관”;
store[207].price = 0;
store[207].type = 4;
store[207].type_eat = 0;

store[208].position = 208;
store[208].url = ”X”;
store[208].name = ”수선관”;
store[208].price = 0;
store[208].type = 4;
store[208].type_eat = 0;

store[209].position = 209;
store[209].url = ”X”;
store[209].name = ”경제관”;
store[209].price = 0;
store[209].type = 4;
store[209].type_eat = 0;

store[210].position = 210;
store[210].url = ”X”;
store[210].name = ”국제관”;
store[210].price = 0;
store[210].type = 4;
store[210].type_eat = 0;

store[211].position = 211;
store[211].url = ”X”;
store[211].name = ”쪽문”;
store[211].price = 0;
store[211].type = 4;
store[211].type_eat = 0;

store[212].position = 212;
store[212].url = ”X”;
store[212].name = ”정문”;
store[212].price = 0;
store[212].type = 4;
store[212].type_eat = 0;

store[213].position = 213;
store[213].url = ”X”;
store[213].name = ”대명거리”;
store[213].price = 0;
store[213].type = 4;
store[213].type_eat = 0;

store[214].position = 214;
store[214].url = ”X”;
store[214].name = ”소나무길”;
store[214].price = 0;
store[214].type = 4;
store[214].type_eat = 0;

store[215].position = 215;
store[215].url = ”X”;
store[215].name = ”대학로”;
store[215].price = 0;
store[215].type = 4;
store[215].type_eat = 0;

store[216].position = 216;
store[216].url = ”X”;
store[216].name = ”600주년기념관”;
store[216].price = 0;
store[216].type = 4;
store[216].type_eat = 0;

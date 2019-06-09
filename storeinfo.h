#pragma once
#define __STOREINFO_H__

typedef struct { //정점 표현에 사용되는 구조체
	int key;
	char url[100];
	char name[100];
	int price;
	int type;
	int type_eat;

	int position;
	int store_to_pos_dist;
	int second_near;
	int store_to_sec_dist;
} Node;

void setStoreInfo(Node store[]) {
	
	//정점
	//119 수선관  120 경제관  121 호암관  122 경영관  123 중앙도서관  124 국제관
	//125 600주년기념관  126 쪽문엘리베이터  127 학교정문  128 올레사거리  129 혜화역4번출구  130 혜화역1번출구

	//Position
	//교내store(0~6) 소나무길store(7~39) 대명거리store(40~54, 108~118)
	//쪽문store(55 - 72)  정문store(73 - 88, 103 - 107)  대학로store(89 - 102)

	// type 식당 = 0, 약국 = 1, 편의점, 마트 = 2, 카페 = 3, 정점 = 4
	// type_eat 식당X = 0 한식 = 1, 일식 = 2, 중식 = 3, 양식 = 4, 고기 = 5, 닭 = 6, 기타 = 7

	//------------------------교내------------------------

	//금잔디 식당
	store[0].position = 122;
	strcpy(store[0].url, "X");
	strcpy(store[0].name, "금잔디식당");
	store[0].price = 5000;
	store[0].type = 0;
	store[0].type_eat = 7;
	store[0].store_to_pos_dist = 0;
	store[0].second_near = 120;
	store[0].store_to_sec_dist = 46;

	//맘스터치(금잔디)
	store[1].position = 122;
	strcpy(store[1].url, "X");
	strcpy(store[1].name, "맘스터치(금잔디)");
	store[1].price = 5000;
	store[1].type = 0;
	store[1].type_eat = 7;
	store[1].store_to_pos_dist = 0;
	store[1].second_near = 120;
	store[1].store_to_sec_dist = 46;

	//CU
	store[2].position = 122;
	strcpy(store[2].url, "X");
	strcpy(store[2].name, "CU(성균관대경영관점)");
	store[2].price = 0;
	store[2].type = 2;
	store[2].type_eat = 0;
	store[2].store_to_pos_dist = 0;
	store[2].second_near = 120;
	store[2].store_to_sec_dist = 46;

	//사랑방
	store[3].position = 122;
	strcpy(store[3].url, "X");
	strcpy(store[3].name, "사랑방");
	store[3].price = 3000;
	store[3].type = 3;
	store[3].type_eat = 0;
	store[3].store_to_pos_dist = 0;
	store[3].second_near = 120;
	store[3].store_to_sec_dist = 46;

	//은행골식당
	store[4].position = 125;
	strcpy(store[4].url, "X");
	strcpy(store[4].name, "은행골 식당");
	store[4].price = 5000;
	store[4].type = 0;
	store[4].type_eat = 7;
	store[4].store_to_pos_dist = 0;
	store[4].second_near = 124;
	store[4].store_to_sec_dist = 121;

	//도미노피자(은행골)
	store[5].position = 125;
	strcpy(store[5].url, "https://web.dominos.co.kr/main");
	strcpy(store[5].name, "도미노피자(은행골)");
	store[5].price = 10000;
	store[5].type = 0;
	store[5].type_eat = 4;
	store[5].store_to_pos_dist = 0;
	store[5].second_near = 124;
	store[5].store_to_sec_dist = 121;

	//서브웨이(은행골)
	store[6].position = 125;
	strcpy(store[6].url, "http://subway.co.kr/");
	strcpy(store[6].name, "서브웨이(은행골)");
	store[6].price = 8000;
	store[6].type = 0;
	store[6].type_eat = 7;
	store[6].store_to_pos_dist = 0;
	store[6].second_near = 124;
	store[6].store_to_sec_dist = 121;

	//-----------------소나무길----------------------

	//명쭈삼
	store[7].position = 128;
	strcpy(store[7].url, "https://www.audwn3.com/");
	strcpy(store[7].name, "명쭈삼");
	store[7].price = 15000;
	store[7].type = 0;
	store[7].type_eat = 1;
	store[7].store_to_pos_dist = 99;
	store[7].second_near = 129;
	store[7].store_to_sec_dist = 251;

	//전설의 짬뽕
	store[8].position = 128;
	strcpy(store[8].url, "http://legendgo.co.kr/web/home.php");
	strcpy(store[8].name, "전설의 짬뽕");
	store[8].price = 10000;
	store[8].type = 0;
	store[8].type_eat = 3;
	store[8].store_to_pos_dist = 116;
	store[8].second_near = 129;
	store[8].store_to_sec_dist = 212;

	//돈돈정
	store[9].position = 128;
	strcpy(store[9].url, "X");
	strcpy(store[9].name, "돈돈정");
	store[9].price = 15000;
	store[9].type = 0;
	store[9].type_eat = 2;
	store[9].store_to_pos_dist = 98;
	store[9].second_near = 129;
	store[9].store_to_sec_dist = 255;

	//뎁짜이
	store[10].position = 128;
	strcpy(store[10].url, "http://www.instagram.com/dep_trai_korea");
	strcpy(store[10].name, "뎁짜이");
	store[10].price = 10000;
	store[10].type = 0;
	store[10].type_eat = 7;
	store[10].store_to_pos_dist = 125;
	store[10].second_near = 129;
	store[10].store_to_sec_dist = 277;

	//깔리
	store[11].position = 128;
	strcpy(store[11].url, "X");
	strcpy(store[11].name, "깔리");
	store[11].price = 15000;
	store[11].type = 0;
	store[11].type_eat = 7;
	store[11].store_to_pos_dist = 125;
	store[11].second_near = 129;
	store[11].store_to_sec_dist = 277;

	//르아브르
	store[12].position = 128;
	strcpy(store[12].url, "http://instagram.com/cafe_lehavre");
	strcpy(store[12].name, "르아브르");
	store[12].price = 5000;
	store[12].type = 3;
	store[12].type_eat = 0;
	store[12].store_to_pos_dist = 69;
	store[12].second_near = 129;
	store[12].store_to_sec_dist = 262;

	//와인한잔
	store[13].position = 128;
	strcpy(store[13].url, "X");
	strcpy(store[13].name, "와인한잔");
	store[13].price = 15000;
	store[13].type = 0;
	store[13].type_eat = 4;
	store[13].store_to_pos_dist = 110;
	store[13].second_near = 129;
	store[13].store_to_sec_dist = 303;

	//현초밥
	store[14].position = 128;
	strcpy(store[14].url, "X");
	strcpy(store[14].name, "현초밥");
	store[14].price = 10000;
	store[14].type = 0;
	store[14].type_eat = 2;
	store[14].store_to_pos_dist = 131;
	store[14].second_near = 129;
	store[14].store_to_sec_dist = 283;

	//은행골
	store[15].position = 128;
	strcpy(store[15].url, "X");
	strcpy(store[15].name, "은행골");
	store[15].price = 15000;
	store[15].type = 0;
	store[15].type_eat = 2;
	store[15].store_to_pos_dist = 201;
	store[15].second_near = 129;
	store[15].store_to_sec_dist = 317;

	//카페 혜화동
	store[16].position = 128;
	strcpy(store[16].url, "X");
	strcpy(store[16].name, "카페 혜화동");
	store[16].price = 8000;
	store[16].type = 3;
	store[16].type_eat = 0;
	store[16].store_to_pos_dist = 182;
	store[16].second_near = 129;
	store[16].store_to_sec_dist = 298;

	//세븐일레븐 명륜카페점 
	store[17].position = 128;
	strcpy(store[17].url, "X");
	strcpy(store[17].name, "세븐일레븐 명륜카페점");
	store[17].price = 0;
	store[17].type = 2;
	store[17].type_eat = 0;
	store[17].store_to_pos_dist = 185;
	store[17].second_near = 129;
	store[17].store_to_sec_dist = 287;

	//정민온누리약국
	store[18].position = 128;
	strcpy(store[18].url, "X");
	strcpy(store[18].name, "정민온누리약국");
	store[18].price = 0;
	store[18].type = 1;
	store[18].type_eat = 0;
	store[18].store_to_pos_dist = 185;
	store[18].second_near = 129;
	store[18].store_to_sec_dist = 287;

	//창화당
	store[19].position = 128;
	strcpy(store[19].url, "http://www.chdang.com");
	strcpy(store[19].name, "창화당");
	store[19].price = 10000;
	store[19].type = 0;
	store[19].type_eat = 1;
	store[19].store_to_pos_dist = 183;
	store[19].second_near = 129;
	store[19].store_to_sec_dist = 299;

	//멘야산다이메
	store[20].position = 128;
	strcpy(store[20].url, "http://www.menyasandaime.co.kr/");
	strcpy(store[20].name, "멘야산다이메");
	store[20].price = 8000;
	store[20].type = 0;
	store[20].type_eat = 2;
	store[20].store_to_pos_dist = 205;
	store[20].second_near = 129;
	store[20].store_to_sec_dist = 321;

	//라미스
	store[21].position = 128;
	strcpy(store[21].url, "X");
	strcpy(store[21].name, "라미스");
	store[21].price = 5000;
	store[21].type = 3;
	store[21].type_eat = 0;
	store[21].store_to_pos_dist = 181;
	store[21].second_near = 129;
	store[21].store_to_sec_dist = 297;

	//부탄츄
	store[22].position = 128;
	strcpy(store[22].url, "http://butanchu.com");
	strcpy(store[22].name, "부탄츄");
	store[22].price = 10000;
	store[22].type = 0;
	store[22].type_eat = 2;
	store[22].store_to_pos_dist = 255;
	store[22].second_near = 129;
	store[22].store_to_sec_dist = 309;

	//서양집
	store[23].position = 128;
	strcpy(store[23].url, "https://www.instagram.com/seoyangzip");
	strcpy(store[23].name, "서양집");
	store[23].price = 15000;
	store[23].type = 0;
	store[23].type_eat = 4;
	store[23].store_to_pos_dist = 255;
	store[23].second_near = 129;
	store[23].store_to_sec_dist = 309;

	//엽기떡볶이
	store[24].position = 128;
	strcpy(store[24].url, "http://www.yupdduk.com/");
	strcpy(store[24].name, "엽기떡볶이");
	store[24].price = 8000;
	store[24].type = 0;
	store[24].type_eat = 7;
	store[24].store_to_pos_dist = 162;
	store[24].second_near = 129;
	store[24].store_to_sec_dist = 283;

	//싸다김밥
	store[25].position = 128;
	strcpy(store[25].url, "X");
	strcpy(store[25].name, "싸다김밥");
	store[25].price = 8000;
	store[25].type = 0;
	store[25].type_eat = 1;
	store[25].store_to_pos_dist = 158;
	store[25].second_near = 129;
	store[25].store_to_sec_dist = 270;

	//캑터스
	store[26].position = 128;
	strcpy(store[26].url, "X");
	strcpy(store[26].name, "캑터스");
	store[26].price = 15000;
	store[26].type = 0;
	store[26].type_eat = 7;
	store[26].store_to_pos_dist = 140;
	store[26].second_near = 129;
	store[26].store_to_sec_dist = 260;

	//봉추찜닭
	store[27].position = 128;
	strcpy(store[27].url, "http://www.bongchu.com");
	strcpy(store[27].name, "봉추찜닭");
	store[27].price = 15000;
	store[27].type = 0;
	store[27].type_eat = 6;
	store[27].store_to_pos_dist = 187;
	store[27].second_near = 129;
	store[27].store_to_sec_dist = 289;

	//교촌치킨
	store[28].position = 128;
	strcpy(store[28].url, "http://www.kyochon.com/");
	strcpy(store[28].name, "교촌치킨");
	store[28].price = 20000;
	store[28].type = 0;
	store[28].type_eat = 6;
	store[28].store_to_pos_dist = 197;
	store[28].second_near = 129;
	store[28].store_to_sec_dist = 299;

	//호호식당
	store[29].position = 128;
	strcpy(store[29].url, "https://www.instagram.com/hohosikdang/");
	strcpy(store[29].name, "호호식당");
	store[29].price = 15000;
	store[29].type = 0;
	store[29].type_eat = 2;
	store[29].store_to_pos_dist = 197;
	store[29].second_near = 129;
	store[29].store_to_sec_dist = 299;

	//정돈
	store[30].position = 128;
	strcpy(store[30].url, "https://blog.naver.com/jungdon0916");
	strcpy(store[30].name, "정돈");
	store[30].price = 15000;
	store[30].type = 0;
	store[30].type_eat = 2;
	store[30].store_to_pos_dist = 302;
	store[30].second_near = 129;
	store[30].store_to_sec_dist = 318;

	//GS25 명륜스타점
	store[31].position = 129;
	strcpy(store[31].url, "X");
	strcpy(store[31].name, "GS25 명륜스타점");
	store[31].price = 0;
	store[31].type = 2;
	store[31].type_eat = 0;
	store[31].store_to_pos_dist = 231;
	store[31].second_near = 128;
	store[31].store_to_sec_dist = 237;

	//메밀향그집
	store[32].position = 129;
	strcpy(store[32].url, "https://www.instagram.com/memilhyang");
	strcpy(store[32].name, "메밀향그집");
	store[32].price = 15000;
	store[32].type = 0;
	store[32].type_eat = 6;
	store[32].store_to_pos_dist = 199;
	store[32].second_near = 128;
	store[32].store_to_sec_dist = 246;

	//쪼리닭
	store[33].position = 129;
	strcpy(store[33].url, "X");
	strcpy(store[33].name, "쪼리닭");
	store[33].price = 15000;
	store[33].type = 0;
	store[33].type_eat = 6;
	store[33].store_to_pos_dist = 198;
	store[33].second_near = 128;
	store[33].store_to_sec_dist = 245;

	//버거파크
	store[34].position = 129;
	strcpy(store[34].url, "http://www.burgerpark.co.kr/");
	strcpy(store[34].name, "버거파크");
	store[34].price = 15000;
	store[34].type = 0;
	store[34].type_eat = 4;
	store[34].store_to_pos_dist = 255;
	store[34].second_near = 128;
	store[34].store_to_sec_dist = 288;

	//커핀그루나루
	store[35].position = 129;
	strcpy(store[35].url, "X");
	strcpy(store[35].name, "커핀그루나루");
	store[35].price = 5000;
	store[35].type = 3;
	store[35].type_eat = 0;
	store[35].store_to_pos_dist = 179;
	store[35].second_near = 128;
	store[35].store_to_sec_dist = 301;

	//CU 대학로광장점
	store[36].position = 129;
	strcpy(store[36].url, "X");
	strcpy(store[36].name, "CU 대학로광장점");
	store[36].price = 0;
	store[36].type = 2;
	store[36].type_eat = 0;
	store[36].store_to_pos_dist = 220;
	store[36].second_near = 128;
	store[36].store_to_sec_dist = 356;

	//새마을식당
	store[37].position = 129;
	strcpy(store[37].url, "http://newmaul.com");
	strcpy(store[37].name, "새마을식당");
	store[37].price = 10000;
	store[37].type = 0;
	store[37].type_eat = 5;
	store[37].store_to_pos_dist = 204;
	store[37].second_near = 128;
	store[37].store_to_sec_dist = 303;

	//파랑새약국
	store[38].position = 129;
	strcpy(store[38].url, "X");
	strcpy(store[38].name, "파랑새약국");
	store[38].price = 0;
	store[38].type = 1;
	store[38].type_eat = 0;
	store[38].store_to_pos_dist = 221;
	store[38].second_near = 128;
	store[38].store_to_sec_dist = 357;

	//서울위드팜약국
	store[39].position = 129;
	strcpy(store[39].url, "X");
	strcpy(store[39].name, "서울위드팜약국");
	store[39].price = 0;
	store[39].type = 1;
	store[39].type_eat = 0;
	store[39].store_to_pos_dist = 234;
	store[39].second_near = 128;
	store[39].store_to_sec_dist = 370;

	//--------------------대명거리----------------------

	//김가네
	store[40].position = 128;
	strcpy(store[40].url, "http://www.gimgane.co.kr");
	strcpy(store[40].name, "김가네");
	store[40].price = 8000;
	store[40].type = 0;
	store[40].type_eat = 1;
	store[40].store_to_pos_dist = 45;
	store[40].second_near = 129;
	store[40].store_to_sec_dist = 218;

	//스시사소우
	store[41].position = 128;
	strcpy(store[41].url, "X");
	strcpy(store[41].name, "스시사소우");
	store[41].price = 15000;
	store[41].type = 0;
	store[41].type_eat = 2;
	store[41].store_to_pos_dist = 45;
	store[41].second_near = 129;
	store[41].store_to_sec_dist = 218;

	//킹스빈커피
	store[42].position = 128;
	strcpy(store[42].url, "X");
	strcpy(store[42].name, "킹스빈커피");
	store[42].price = 5000;
	store[42].type = 3;
	store[42].type_eat = 0;
	store[42].store_to_pos_dist = 27;
	store[42].second_near = 129;
	store[42].store_to_sec_dist = 264;

	//내찜닭
	store[43].position = 128;
	strcpy(store[43].url, "X");
	strcpy(store[43].name, "내찜닭");
	store[43].price = 15000;
	store[43].type = 0;
	store[43].type_eat = 6;
	store[43].store_to_pos_dist = 41;
	store[43].second_near = 129;
	store[43].store_to_sec_dist = 203;

	//놀부부대찌개
	store[44].position = 128;
	strcpy(store[44].url, "https://www.nolboo.co.kr/pages/business/brand_boodae.asp");
	strcpy(store[44].name, "놀부부대찌개");
	store[44].price = 10000;
	store[44].type = 0;
	store[44].type_eat = 1;
	store[44].store_to_pos_dist = 60;
	store[44].second_near = 129;
	store[44].store_to_sec_dist = 203;

	//프루츠
	store[45].position = 128;
	strcpy(store[45].url, "X");
	strcpy(store[45].name, "프루츠");
	store[45].price = 10000;
	store[45].type = 0;
	store[45].type_eat = 7;
	store[45].store_to_pos_dist = 63;
	store[45].second_near = 129;
	store[45].store_to_sec_dist = 181;

	//식탁의목적
	store[46].position = 128;
	strcpy(store[46].url, "X");
	strcpy(store[46].name, "식탁의목적");
	store[46].price = 8000;
	store[46].type = 0;
	store[46].type_eat = 1;
	store[46].store_to_pos_dist = 120;
	store[46].second_near = 129;
	store[46].store_to_sec_dist = 172;

	//플라잉볼익스프레스
	store[47].position = 128;
	strcpy(store[47].url, "http://flyingbowlexpress.com/");
	strcpy(store[47].name, "플라잉볼익스프레스");
	store[47].price = 8000;
	store[47].type = 0;
	store[47].type_eat = 4;
	store[47].store_to_pos_dist = 146;
	store[47].second_near = 129;
	store[47].store_to_sec_dist = 146;

	//산쪼메
	store[48].position = 128;
	strcpy(store[48].url, "http://sanchome.co.kr");
	strcpy(store[48].name, "산쪼메");
	store[48].price = 8000;
	store[48].type = 0;
	store[48].type_eat = 2;
	store[48].store_to_pos_dist = 146;
	store[48].second_near = 129;
	store[48].store_to_sec_dist = 146;

	//육회한연어
	store[49].position = 128;
	strcpy(store[49].url, "http://www.happysalmon.co.kr/");
	strcpy(store[49].name, "육회한연어");
	store[49].price = 15000;
	store[49].type = 0;
	store[49].type_eat = 5;
	store[49].store_to_pos_dist = 113;
	store[49].second_near = 129;
	store[49].store_to_sec_dist = 179;

	//혜화수약국
	store[50].position = 129;
	strcpy(store[50].url, "X");
	strcpy(store[50].name, "혜화수약국");
	store[50].price = 0;
	store[50].type = 1;
	store[50].type_eat = 0;
	store[50].store_to_pos_dist = 139;
	store[50].second_near = 128;
	store[50].store_to_sec_dist = 159;

	//도쿄스테이크
	store[51].position = 129;
	strcpy(store[51].url, "http://tokyosteak.co.kr");
	strcpy(store[51].name, "도쿄스테이크");
	store[51].price = 10000;
	store[51].type = 0;
	store[51].type_eat = 2;
	store[51].store_to_pos_dist = 145;
	store[51].second_near = 128;
	store[51].store_to_sec_dist = 177;

	//하루가
	store[52].position = 128;
	strcpy(store[52].url, "X");
	strcpy(store[52].name, "하루가");
	store[52].price = 10000;
	store[52].type = 0;
	store[52].type_eat = 7;
	store[52].store_to_pos_dist = 132;
	store[52].second_near = 129;
	store[52].store_to_sec_dist = 145;

	//혼카츠
	store[53].position = 129;
	strcpy(store[53].url, "X");
	strcpy(store[53].name, "혼카츠");
	store[53].price = 10000;
	store[53].type = 0;
	store[53].type_eat = 2;
	store[53].store_to_pos_dist = 103;
	store[53].second_near = 128;
	store[53].store_to_sec_dist = 195;

	//엉터리생고기
	store[54].position = 129;
	strcpy(store[54].url, "X");
	strcpy(store[54].name, "엉터리생고기");
	store[54].price = 10000;
	store[54].type = 0;
	store[54].type_eat = 5;
	store[54].store_to_pos_dist = 93;
	store[54].second_near = 128;
	store[54].store_to_sec_dist = 206;

	//홍콩반점
	store[108].position = 129;
	strcpy(store[108].url, "http://www.theborn.co.kr/theborn_brand/zzambbong");
	strcpy(store[108].name, "홍콩반점");
	store[108].price = 5000;
	store[108].type = 0;
	store[108].type_eat = 3;
	store[108].store_to_pos_dist = 90;
	store[108].second_near = 128;
	store[108].store_to_sec_dist = 208;

	//서피동파
	store[109].position = 129;
	strcpy(store[109].url, "X");
	strcpy(store[109].name, "서피동파");
	store[109].price = 10000;
	store[109].type = 0;
	store[109].type_eat = 7;
	store[109].store_to_pos_dist = 173;
	store[109].second_near = 128;
	store[109].store_to_sec_dist = 198;

	//CU대학로2호점
	store[110].position = 129;
	strcpy(store[110].url, "X");
	strcpy(store[110].name, "CU대학로2호점");
	store[110].price = 0;
	store[110].type = 2;
	store[110].type_eat = 0;
	store[110].store_to_pos_dist = 99;
	store[110].second_near = 128;
	store[110].store_to_sec_dist = 210;

	//맘스터치
	store[111].position = 129;
	strcpy(store[111].url, "http://www.momstouch.co.kr");
	strcpy(store[111].name, "맘스터치");
	store[111].price = 8000;
	store[111].type = 0;
	store[111].type_eat = 7;
	store[111].store_to_pos_dist = 103;
	store[111].second_near = 128;
	store[111].store_to_sec_dist = 214;

	//마녀주방
	store[112].position = 129;
	strcpy(store[112].url, "https://witchskitchen.co.kr");
	strcpy(store[112].name, "마녀주방");
	store[112].price = 20000;
	store[112].type = 0;
	store[112].type_eat = 4;
	store[112].store_to_pos_dist = 85;
	store[112].second_near = 128;
	store[112].store_to_sec_dist = 233;

	//통큰갈비
	store[113].position = 129;
	strcpy(store[113].url, "http://www.통큰갈비.com");
	strcpy(store[113].name, "통큰갈비");
	store[113].price = 12000;
	store[113].type = 0;
	store[113].type_eat = 5;
	store[113].store_to_pos_dist = 114;
	store[113].second_near = 128;
	store[113].store_to_sec_dist = 243;

	//꼬꼬아찌
	store[114].position = 129;
	strcpy(store[114].url, "X");
	strcpy(store[114].name, "꼬꼬아찌");
	store[114].price = 20000;
	store[114].type = 0;
	store[114].type_eat = 6;
	store[114].store_to_pos_dist = 83;
	store[114].second_near = 128;
	store[114].store_to_sec_dist = 256;

	//할리스커피
	store[115].position = 129;
	strcpy(store[115].url, "http://www.hollys.co.kr");
	strcpy(store[115].name, "할리스커피");
	store[115].price = 5000;
	store[115].type = 3;
	store[115].type_eat = 0;
	store[115].store_to_pos_dist = 21;
	store[115].second_near = 128;
	store[115].store_to_sec_dist = 278;

	//GS25혜화대명점
	store[116].position = 129;
	strcpy(store[116].url, "X");
	strcpy(store[116].name, "GS25혜화대명점");
	store[116].price = 0;
	store[116].type = 2;
	store[116].type_eat = 0;
	store[116].store_to_pos_dist = 77;
	store[116].second_near = 128;
	store[116].store_to_sec_dist = 277;

	//노랑통닭
	store[117].position = 129;
	strcpy(store[117].url, "https://norangtongdak.co.kr/");
	strcpy(store[117].name, "노랑통닭");
	store[117].price = 15000;
	store[117].type = 0;
	store[117].type_eat = 6;
	store[117].store_to_pos_dist = 84;
	store[117].second_near = 128;
	store[117].store_to_sec_dist = 279;

	//동네아저씨치킨
	store[118].position = 129;
	strcpy(store[118].url, "X");
	strcpy(store[118].name, "동네아저씨치킨");
	store[118].price = 25000;
	store[118].type = 0;
	store[118].type_eat = 6;
	store[118].store_to_pos_dist = 92;
	store[118].second_near = 128;
	store[118].store_to_sec_dist = 288;

	//-------------------쪽문------------------------

	store[57].position = 126;
	strcpy(store[57].url, "X");
	strcpy(store[57].name, "밥은");
	store[57].price = 5000;
	store[57].type = 0;
	store[57].type_eat = 1;
	store[57].store_to_pos_dist = 89;
	store[57].second_near = 122;
	store[57].store_to_sec_dist = 475;

	store[56].position = 126;
	strcpy(store[56].url, "X");
	strcpy(store[56].name, "후쿠후쿠");
	store[56].price = 8000;
	store[56].type = 0;
	store[56].type_eat = 2;
	store[56].store_to_pos_dist = 90;
	store[56].second_near = 122;
	store[56].store_to_sec_dist = 476;

	store[66].position = 126;
	strcpy(store[66].url, "X");
	strcpy(store[66].name, "천하제일탕수육");
	store[66].price = 5000;
	store[66].type = 0;
	store[66].type_eat = 7;
	store[66].store_to_pos_dist = 182;
	store[66].second_near = 123;
	store[66].store_to_sec_dist = 609;

	store[55].position = 126;
	strcpy(store[55].url, "X");
	strcpy(store[55].name, "후라이팬");
	store[55].price = 8000;
	store[55].type = 0;
	store[55].type_eat = 7;
	store[55].store_to_pos_dist = 40;
	store[55].second_near = 122;
	store[55].store_to_sec_dist = 426;

	store[58].position = 126;
	strcpy(store[58].url, "X");
	strcpy(store[58].name, "쇼타돈부리");
	store[58].price = 8000;
	store[58].type = 0;
	store[58].type_eat = 2;
	store[58].store_to_pos_dist = 122;
	store[58].second_near = 122;
	store[58].store_to_sec_dist = 505;


	store[59].position = 126;
	strcpy(store[59].url, "X");
	strcpy(store[59].name, "청춘직화");
	store[59].price = 8000;
	store[59].type = 0;
	store[59].type_eat = 1;
	store[59].store_to_pos_dist = 118;
	store[59].second_near = 122;
	store[59].store_to_sec_dist = 501;

	store[61].position = 125;
	strcpy(store[61].url, "X");
	strcpy(store[61].name, "우보장");
	store[61].price = 8000;
	store[61].type = 0;
	store[61].type_eat = 3;
	store[61].store_to_pos_dist = 240;
	store[61].second_near = 123;
	store[61].store_to_sec_dist = 661;

	store[60].position = 126;
	strcpy(store[60].url, "X");
	strcpy(store[60].name, "서퍼피자");
	store[60].price = 10000;
	store[60].type = 0;
	store[60].type_eat = 4;
	store[60].store_to_pos_dist = 86;
	store[60].second_near = 122;
	store[60].store_to_sec_dist = 469;

	store[62].position = 126;
	strcpy(store[62].url, "http://m.bongousse.net/");
	strcpy(store[62].name, "봉구스밥버거");
	store[62].price = 5000;
	store[62].type = 0;
	store[62].type_eat = 1;
	store[62].store_to_pos_dist = 150;
	store[62].second_near = 123;
	store[62].store_to_sec_dist = 654;

	store[64].position = 126;
	strcpy(store[64].url, "X");
	strcpy(store[64].name, "더닭");
	store[64].price = 8000;
	store[64].type = 0;
	store[64].type_eat = 6;
	store[64].store_to_pos_dist = 223;
	store[64].second_near = 123;
	store[64].store_to_sec_dist = 644;

	store[63].position = 126;
	strcpy(store[63].url, "X");
	strcpy(store[63].name, "몬스터부리또");
	store[63].price = 5000;
	store[63].type = 0;
	store[63].type_eat = 7;
	store[63].store_to_pos_dist = 91;
	store[63].second_near = 122;
	store[63].store_to_sec_dist = 474;

	store[65].position = 126;
	strcpy(store[65].url, "X");
	strcpy(store[65].name, "돈앤까");
	store[65].price = 8000;
	store[65].type = 0;
	store[65].type_eat = 2;
	store[65].store_to_pos_dist = 99;
	store[65].second_near = 122;
	store[65].store_to_sec_dist = 483;

	store[71].position = 126;
	strcpy(store[71].url, "https://www.facebook.com/koffisix");
	strcpy(store[71].name, "쥬스식스");
	store[71].price = 5000;
	store[71].type = 3;
	store[71].type_eat = 0;
	store[71].store_to_pos_dist = 139;
	store[71].second_near = 123;
	store[71].store_to_sec_dist = 560;

	store[70].position = 126;
	strcpy(store[70].url, "X");
	strcpy(store[70].name, "이마트24편의점");
	store[70].price = 0;
	store[70].type = 2;
	store[70].type_eat = 0;
	store[70].store_to_pos_dist = 120;
	store[70].second_near = 122;
	store[70].store_to_sec_dist = 502;

	store[72].position = 126;
	strcpy(store[72].url, "X");
	strcpy(store[72].name, "GS25명륜성대점");
	store[72].price = 0;
	store[72].type = 2;
	store[72].type_eat = 0;
	store[72].store_to_pos_dist = 298;
	store[72].second_near = 127;
	store[72].store_to_sec_dist = 367;

	store[69].position = 126;
	strcpy(store[69].url, "X");
	strcpy(store[69].name, "탑할인마트");
	store[69].price = 0;
	store[69].type = 2;
	store[69].type_eat = 0;
	store[69].store_to_pos_dist = 253;
	store[69].second_near = 127;
	store[69].store_to_sec_dist = 401;

	store[67].position = 126;
	strcpy(store[67].url, "X");
	strcpy(store[67].name, "보성약국");
	store[67].price = 0;
	store[67].type = 1;
	store[67].type_eat = 0;
	store[67].store_to_pos_dist = 182;
	store[67].second_near = 123;
	store[67].store_to_sec_dist = 565;

	store[68].position = 126;
	strcpy(store[68].url, "X");
	strcpy(store[68].name, "명륜시장약국");
	store[68].price = 0;
	store[68].type = 1;
	store[68].type_eat = 0;
	store[68].store_to_pos_dist = 320;
	store[68].second_near = 127;
	store[68].store_to_sec_dist = 374;




	//----------------정문------------------------

	store[87].position = 127;
	strcpy(store[87].url, "http://www.cknia.com/");
	strcpy(store[87].name, "치킨매니아");
	store[87].price = 15000;
	store[87].type = 0;
	store[87].type_eat = 6;
	store[87].store_to_pos_dist = 132;
	store[87].second_near = 126;
	store[87].store_to_sec_dist = 536;

	store[88].position = 127;
	strcpy(store[88].url, "X");
	strcpy(store[88].name, "명쭈3");
	store[88].price = 15000;
	store[88].type = 0;
	store[88].type_eat = 1;
	store[88].store_to_pos_dist = 377;
	store[88].second_near = 127;
	store[88].store_to_sec_dist = 947;

	store[74].position = 127;
	strcpy(store[74].url, "X");
	strcpy(store[74].name, "홍곱창");
	store[74].price = 15000;
	store[74].type = 0;
	store[74].type_eat = 5;
	store[74].store_to_pos_dist = 137;
	store[74].second_near = 128;
	store[74].store_to_sec_dist = 236;

	store[104].position = 127;
	strcpy(store[104].url, "http://www.sinjeon.co.kr/");
	strcpy(store[104].name, "신전떡볶이");
	store[104].price = 5000;
	store[104].type = 0;
	store[104].type_eat = 7;
	store[104].store_to_pos_dist = 116;
	store[104].second_near = 128;
	store[104].store_to_sec_dist = 169;

	store[73].position = 127;
	strcpy(store[73].url, "X");
	strcpy(store[73].name, "포보");
	store[73].price = 8000;
	store[73].type = 0;
	store[73].type_eat = 7;
	store[73].store_to_pos_dist = 265;
	store[73].second_near = 128;
	store[73].store_to_sec_dist = 34;

	store[80].position = 127;
	strcpy(store[80].url, "X");
	strcpy(store[80].name, "화로상회");
	store[80].price = 15000;
	store[80].type = 0;
	store[80].type_eat = 5;
	store[80].store_to_pos_dist = 134;
	store[80].second_near = 128;
	store[80].store_to_sec_dist = 206;

	store[78].position = 127;
	strcpy(store[78].url, "X");
	strcpy(store[78].name, "692고기포차");
	store[78].price = 20000;
	store[78].type = 0;
	store[78].type_eat = 5;
	store[78].store_to_pos_dist = 202;
	store[78].second_near = 128;
	store[78].store_to_sec_dist = 132;

	store[77].position = 127;
	strcpy(store[77].url, "http://www.ssaum.co.kr/");
	strcpy(store[77].name, "싸움의고수");
	store[77].price = 10000;
	store[77].type = 0;
	store[77].type_eat = 5;
	store[77].store_to_pos_dist = 116;
	store[77].second_near = 128;
	store[77].store_to_sec_dist = 169;

	store[107].position = 127;
	strcpy(store[107].url, "http://www.mcdonalds.co.kr/www/kor/main/main.do");
	strcpy(store[107].name, "맥도날드");
	store[107].price = 8000;
	store[107].type = 0;
	store[107].type_eat = 7;
	store[107].store_to_pos_dist = 128;
	store[107].second_near = 128;
	store[107].store_to_sec_dist = 48;

	store[106].position = 127;
	strcpy(store[106].url, "http://pizzaschool.net/");
	strcpy(store[106].name, "피자스쿨");
	store[106].price = 8000;
	store[106].type = 0;
	store[106].type_eat = 4;
	store[106].store_to_pos_dist = 143;
	store[106].second_near = 128;
	store[106].store_to_sec_dist = 156;

	store[103].position = 127;
	strcpy(store[103].url, "X");
	strcpy(store[103].name, "나누미");
	store[103].price = 5000;
	store[103].type = 0;
	store[103].type_eat = 1;
	store[103].store_to_pos_dist = 179;
	store[103].second_near = 128;
	store[103].store_to_sec_dist = 94;

	store[85].position = 127;
	strcpy(store[85].url, "X");
	strcpy(store[85].name, "명륜왕만두");
	store[85].price = 5000;
	store[85].type = 0;
	store[85].type_eat = 7;
	store[85].store_to_pos_dist = 257;
	store[85].second_near = 128;
	store[85].store_to_sec_dist = 54;

	store[86].position = 127;
	strcpy(store[86].url, "http://milsup.co.kr/");
	strcpy(store[86].name, "밀숲");
	store[86].price = 8000;
	store[86].type = 0;
	store[86].type_eat = 1;
	store[86].store_to_pos_dist = 293;
	store[86].second_near = 128;
	store[86].store_to_sec_dist = 27;

	store[81].position = 127;
	strcpy(store[81].url, "X");
	strcpy(store[81].name, "기꾸스시");
	store[81].price = 15000;
	store[81].type = 0;
	store[81].type_eat = 2;
	store[81].store_to_pos_dist = 265;
	store[81].second_near = 128;
	store[81].store_to_sec_dist = 34;

	store[105].position = 127;
	strcpy(store[105].url, "X");
	strcpy(store[105].name, "천향록");
	store[105].price = 15000;
	store[105].type = 0;
	store[105].type_eat = 3;
	store[105].store_to_pos_dist = 177;
	store[105].second_near = 128;
	store[105].store_to_sec_dist = 122;

	store[82].position = 127;
	strcpy(store[82].url, "http://www.ddingddong.co.kr/");
	strcpy(store[82].name, "띵똥와플");
	store[82].price = 5000;
	store[82].type = 3;
	store[82].type_eat = 0;
	store[82].store_to_pos_dist = 181;
	store[82].second_near = 128;
	store[82].store_to_sec_dist = 92;


	store[84].position = 127;
	strcpy(store[84].url, "https://www.ediya.com/");
	strcpy(store[84].name , "이디야");
	store[84].price = 5000;
	store[84].type = 3;
	store[84].type_eat = 0;
	store[84].store_to_pos_dist = 237;
	store[84].second_near = 128;
	store[84].store_to_sec_dist = 86;

	store[83].position = 127;
	strcpy(store[83].url, "https://www.tomntoms.com/");
	strcpy(store[83].name, "탐앤탐스");
	store[83].price = 5000;
	store[83].type = 3;
	store[83].type_eat = 0;
	store[83].store_to_pos_dist = 339;
	store[83].second_near = 128;
	store[83].store_to_sec_dist = 67;

	store[76].position = 127;
	strcpy(store[76].url, "X");
	strcpy(store[76].name, "이마트24");
	store[76].price = 0;
	store[76].type = 2;
	store[76].type_eat = 0;
	store[76].store_to_pos_dist = 175;
	store[76].second_near = 128;
	store[76].store_to_sec_dist = 116;

	store[75].position = 127;
	strcpy(store[75].url, "X");
	strcpy(store[75].name, "세븐일레븐성대점");
	store[75].price = 0;
	store[75].type = 2;
	store[75].type_eat = 0;
	store[75].store_to_pos_dist = 123;
	store[75].second_near = 128;
	store[75].store_to_sec_dist = 207;

	store[79].position = 127;
	strcpy(store[79].url, "X");
	strcpy(store[79].name, "GS25성대입구점");
	store[79].price = 0;
	store[79].type = 2;
	store[79].type_eat = 0;
	store[79].store_to_pos_dist = 265;
	store[79].second_near = 128;
	store[79].store_to_sec_dist = 8;


	//---------------------대학로----------------------------

	store[89].position = 130;
	strcpy(store[89].url, "http://abiko.kr/");
	strcpy(store[89].name, "아비꼬카레");
	store[89].price = 10000;
	store[89].type = 0;
	store[89].type_eat = 2;
	store[89].store_to_pos_dist = 177;
	store[89].second_near = 129;
	store[89].store_to_sec_dist = 291;

	store[90].position = 130;
	strcpy(store[90].url, "http://www.cocoichibanya.co.kr/");
	strcpy(store[90].name, "코코이찌방야");
	store[90].price = 10000;
	store[90].type = 0;
	store[90].type_eat = 2;
	store[90].store_to_pos_dist = 110;
	store[90].second_near = 129;
	store[90].store_to_sec_dist = 198;

	store[92].position = 130;
	strcpy(store[92].url, "https://www.facebook.com/daepochicken");
	strcpy(store[92].name, "대포찜닭");
	store[92].price = 15000;
	store[92].type = 0;
	store[92].type_eat = 6;
	store[92].store_to_pos_dist = 303;
	store[92].second_near = 129;
	store[92].store_to_sec_dist = 383;

	store[98].position = 130;
	strcpy(store[98].url, "http://mpizzeriao.fordining.kr/");
	strcpy(store[98].name, "핏제리아오");
	store[98].price = 20000;
	store[98].type = 0;
	store[98].type_eat = 4;
	store[98].store_to_pos_dist = 516;
	store[98].second_near = 129;
	store[98].store_to_sec_dist = 633;

	store[91].position = 130;
	strcpy(store[91].url, "X");
	strcpy(store[91].name, "낙산가든");
	store[91].price = 20000;
	store[91].type = 0;
	store[91].type_eat = 5;
	store[91].store_to_pos_dist = 49;
	store[91].second_near = 129;
	store[91].store_to_sec_dist = 172;

	store[101].position = 130;
	strcpy(store[101].url, "X");
	strcpy(store[101].name, "리얼시카고피자");
	store[101].price = 20000;
	store[101].type = 0;
	store[101].type_eat = 4;
	store[101].store_to_pos_dist = 235;
	store[101].second_near = 129;
	store[101].store_to_sec_dist = 352;

	store[100].position = 130;
	strcpy(store[100].url, "https://www.tokkijung.co.kr/");
	strcpy(store[100].name, "토끼정");
	store[100].price = 15000;
	store[100].type = 0;
	store[100].type_eat = 7;
	store[100].store_to_pos_dist = 454;
	store[100].second_near = 129;
	store[100].store_to_sec_dist = 571;

	store[97].position = 130;
	strcpy(store[97].url, "X");
	strcpy(store[97].name, "돌쇠아저씨");
	store[97].price = 10000;
	store[97].type = 0;
	store[97].type_eat = 7;
	store[97].store_to_pos_dist = 113;
	store[97].second_near = 129;
	store[97].store_to_sec_dist = 176;

	store[99].position = 130;
	strcpy(store[99].url, "https://www.kfckorea.com/");
	strcpy(store[99].name, "KFC");
	store[99].price = 8000;
	store[99].type = 0;
	store[99].type_eat = 7;
	store[99].store_to_pos_dist = 175;
	store[99].second_near = 129;
	store[99].store_to_sec_dist = 293;

	store[95].position = 130;
	strcpy(store[95].url, "http://www.emoikorea.com/");
	strcpy(store[95].name, "에머이");
	store[95].price = 10000;
	store[95].type = 0;
	store[95].type_eat = 7;
	store[95].store_to_pos_dist = 314;
	store[95].second_near = 129;
	store[95].store_to_sec_dist = 431;

	store[96].position = 130;
	strcpy(store[96].url, "http://www.nipongnaepong.co.kr/");
	strcpy(store[96].name, "니뽕내뽕");
	store[96].price = 10000;
	store[96].type = 0;
	store[96].type_eat = 4;
	store[96].store_to_pos_dist = 409;
	store[96].second_near = 129;
	store[96].store_to_sec_dist = 492;

	store[102].position = 130;
	strcpy(store[102].url, "https://www.sulbing.com/main.php");
	strcpy(store[102].name, "설빙");
	store[102].price = 5000;
	store[102].type = 3;
	store[102].type_eat = 0;
	store[102].store_to_pos_dist = 178;
	store[102].second_near = 129;
	store[102].store_to_sec_dist = 296;

	store[94].position = 130;
	strcpy(store[94].url, "X");
	strcpy(store[94].name, "하트약국");
	store[94].price = 0;
	store[94].type = 1;
	store[94].type_eat = 0;
	store[94].store_to_pos_dist = 72;
	store[94].second_near = 129;
	store[94].store_to_sec_dist = 190;

	store[93].position = 130;
	strcpy(store[93].url, "X");
	strcpy(store[93].name, "CU종로동숭동점");
	store[93].price = 0;
	store[93].type = 2;
	store[93].type_eat = 0;
	store[93].store_to_pos_dist = 116;
	store[93].second_near = 129;
	store[93].store_to_sec_dist = 234;


	//----------------------------건물정점------------------------------
	
	store[119].position = 119;
	strcpy(store[119].url, "X");
	strcpy(store[119].name, "수선관");
	store[119].price = 0;
	store[119].type = 4;
	store[119].type_eat = 0;
	store[119].store_to_pos_dist = 0;
	store[119].second_near = 121;
	store[119].store_to_sec_dist = 83;

	store[120].position = 120;
	strcpy(store[120].url, "X");
	strcpy(store[120].name, "경제관");
	store[120].price = 0;
	store[120].type = 4;
	store[120].type_eat = 0;
	store[120].store_to_pos_dist = 0;
	store[120].second_near = 122;
	store[120].store_to_sec_dist = 46;

	store[121].position = 121;
	strcpy(store[121].url, "X");
	strcpy(store[121].name, "호암관");
	store[121].price = 0;
	store[121].type = 4;
	store[121].type_eat = 0;
	store[121].store_to_pos_dist = 0;
	store[121].second_near = 119;
	store[121].store_to_sec_dist = 83;

	store[122].position = 122;
	strcpy(store[122].url, "X");
	strcpy(store[122].name, "경영관");
	store[122].price = 0;
	store[122].type = 4;
	store[122].type_eat = 0;
	store[122].store_to_pos_dist = 0;
	store[122].second_near = 120;
	store[122].store_to_sec_dist = 46;

	store[123].position = 123;
	strcpy(store[123].url, "X");
	strcpy(store[123].name, "중앙도서관");
	store[123].price = 0;
	store[123].type = 4;
	store[123].type_eat = 0;
	store[123].store_to_pos_dist = 0;
	store[123].second_near = 122;
	store[123].store_to_sec_dist = 92;

	store[124].position = 124;
	strcpy(store[124].url, "X");
	strcpy(store[124].name, "국제관");
	store[124].price = 0;
	store[124].type = 4;
	store[124].type_eat = 0;
	store[124].store_to_pos_dist = 0;
	store[124].second_near = 125;
	store[124].store_to_sec_dist = 121;

	store[125].position = 125;
	strcpy(store[125].url, "X");
	strcpy(store[125].name, "600주년기념관");
	store[125].price = 0;
	store[125].type = 4;
	store[125].type_eat = 0;
	store[125].store_to_pos_dist = 0;
	store[125].second_near = 124;
	store[125].store_to_sec_dist = 121;

	store[126].position = 126;
	strcpy(store[126].url, "X");
	strcpy(store[126].name, "쪽문엘리베이터");
	store[126].price = 0;
	store[126].type = 4;
	store[126].type_eat = 0;
	store[126].store_to_pos_dist = 0;
	store[126].second_near = 123;
	store[126].store_to_sec_dist = 113;


	store[127].position = 127;
	strcpy(store[127].url, "X");
	strcpy(store[127].name, "학교정문");
	store[127].price = 0;
	store[127].type = 4;
	store[127].type_eat = 0;
	store[127].store_to_pos_dist = 0;
	store[127].second_near = 128;
	store[127].store_to_sec_dist = 278;

	store[128].position = 128;
	strcpy(store[128].url, "X");
	strcpy(store[128].name, "올레사거리");
	store[128].price = 0;
	store[128].type = 4;
	store[128].type_eat = 0;
	store[128].store_to_pos_dist = 0;
	store[128].second_near = 127;
	store[128].store_to_sec_dist = 278;

	store[129].position = 129;
	strcpy(store[129].url, "X");
	strcpy(store[129].name, "혜화역4번출구");
	store[129].price = 0;
	store[129].type = 4;
	store[129].type_eat = 0;
	store[129].store_to_pos_dist = 0;
	store[129].second_near = 130;
	store[129].store_to_sec_dist = 152;

	store[130].position = 130;
	strcpy(store[130].url, "X");
	strcpy(store[130].name, "혜화역1번출구");
	store[130].price = 0;
	store[130].type = 4;
	store[130].type_eat = 0;
	store[130].store_to_pos_dist = 0;
	store[130].second_near = 129;
	store[130].store_to_sec_dist = 152;
}
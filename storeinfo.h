#pragma once
#define __STOREINFO_H__

typedef struct { //���� ǥ���� ���Ǵ� ����ü
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
	
	//����
	//200�濵�� 201�߾ӵ�����  202�ʹ�����������  
	//203�б�����  204��ȭ��4���ⱸ(���Ÿ�213)  
	//205�÷���Ÿ�  206��ȭ��1���ⱸ(< -215)
	//207ȣ�ϰ� 208������ 209������ 210������

	//Position
	//����store(0~6) �ҳ�����store(7~39) ���Ÿ�store(40~54, 108~118)
	//�ʹ�store(55 - 72)  ����store(69 - 88, 103 - 107)  ���з�store(89 - 102)


	//------------------------����-------------------------

	//���ܵ� �Ĵ�
	store[0].position = 200;
	strcpy(store[0].url, "X");
	strcpy(store[0].name, "���ܵ�Ĵ�");
	store[0].price = 5000;
	store[0].type = 0;
	store[0].type_eat = 7;
	store[0].store_to_pos_dist = 0;
	store[0].second_near = 201;
	store[0].store_to_sec_dist = 92;

	//������ġ(���ܵ�)
	store[1].position = 200;
	strcpy(store[1].url, "X");
	strcpy(store[1].name, "������ġ(���ܵ�)");
	store[1].price = 5000;
	store[1].type = 0;
	store[1].type_eat = 7;
	store[1].store_to_pos_dist = 0;
	store[1].second_near = 201;
	store[1].store_to_sec_dist = 92;

	//CU
	store[2].position = 200;
	strcpy(store[2].url, "X");
	strcpy(store[2].name, "CU");
	store[2].price = 0;
	store[2].type = 2;
	store[2].type_eat = 0;
	store[2].store_to_pos_dist = 0;
	store[2].second_near = 201;
	store[2].store_to_sec_dist = 92;

	//�����
	store[3].position = 200;
	strcpy(store[3].url, "X");
	strcpy(store[3].name, "�����");
	store[3].price = 3000;
	store[3].type = 3;
	store[3].type_eat = 0;
	store[3].store_to_pos_dist = 0;
	store[3].second_near = 201;
	store[3].store_to_sec_dist = 92;

	//�����Ĵ�
	store[4].position = 216;
	strcpy(store[4].url, "X");
	strcpy(store[4].name, "����� �Ĵ�");
	store[4].price = 5000;
	store[4].type = 0;
	store[4].type_eat = 7;
	store[4].store_to_pos_dist = 0;
	store[4].second_near = 210;
	store[4].store_to_sec_dist = 121;

	//���̳�����(�����)
	store[5].position = 216;
	strcpy(store[5].url, "https://web.dominos.co.kr/main");
	strcpy(store[5].name, "���̳�����(�����)");
	store[5].price = 10000;
	store[5].type = 0;
	store[5].type_eat = 4;
	store[5].store_to_pos_dist = 0;
	store[5].second_near = 210;
	store[5].store_to_sec_dist = 121;

	//�������(�����)
	store[6].position = 216;
	strcpy(store[6].url, "http://subway.co.kr/");
	strcpy(store[6].name, "�������(�����)");
	store[6].price = 8000;
	store[6].type = 0;
	store[6].type_eat = 7;
	store[6].store_to_pos_dist = 0;
	store[6].second_near = 210;
	store[6].store_to_sec_dist = 121;

	//-------------------�ҳ�����----------------------

	//���޻�
	store[7].position = 205;
	strcpy(store[7].url, "https://www.audwn3.com/");
	strcpy(store[7].name, "���޻�");
	store[7].price = 15000;
	store[7].type = 0;
	store[7].type_eat = 1;
	store[7].store_to_pos_dist = 99;
	store[7].second_near = 204;
	store[7].store_to_sec_dist = 251;

	//������ «��
	store[8].position = 205;
	strcpy(store[8].url, "www.legendgo.co.kr");
	strcpy(store[8].name, "������ «��");
	store[8].price = 10000;
	store[8].type = 0;
	store[8].type_eat = 3;
	store[8].store_to_pos_dist = 116;
	store[8].second_near = 204;
	store[8].store_to_sec_dist = 212;

	//������
	store[9].position = 205;
	strcpy(store[9].url, "X");
	strcpy(store[9].name, "������");
	store[9].price = 15000;
	store[9].type = 0;
	store[9].type_eat = 2;
	store[9].store_to_pos_dist = 98;
	store[9].second_near = 204;
	store[9].store_to_sec_dist = 255;

	//��¥��
	store[10].position = 205;
	strcpy(store[10].url, "http://www.instagram.com/dep_trai_korea");
	strcpy(store[10].name, "��¥��");
	store[10].price = 10000;
	store[10].type = 0;
	store[10].type_eat = 7;
	store[10].store_to_pos_dist = 125;
	store[10].second_near = 204;
	store[10].store_to_sec_dist = 277;

	//��
	store[11].position = 205;
	strcpy(store[11].url, "X");
	strcpy(store[11].name, "��");
	store[11].price = 15000;
	store[11].type = 0;
	store[11].type_eat = 7;
	store[11].store_to_pos_dist = 125;
	store[11].second_near = 204;
	store[11].store_to_sec_dist = 277;

	//���ƺ긣
	store[12].position = 205;
	strcpy(store[12].url, "http://instagram.com/cafe_lehavre");
	strcpy(store[12].name, "���ƺ긣");
	store[12].price = 5000;
	store[12].type = 3;
	store[12].type_eat = 0;
	store[12].store_to_pos_dist = 69;
	store[12].second_near = 205;
	store[12].store_to_sec_dist = 262;

	//��������
	store[13].position = 205;
	strcpy(store[13].url, "X");
	strcpy(store[13].name, "��������");
	store[13].price = 15000;
	store[13].type = 0;
	store[13].type_eat = 4;
	store[13].store_to_pos_dist = 110;
	store[13].second_near = 204;
	store[13].store_to_sec_dist = 303;

	//���ʹ�
	store[14].position = 205;
	strcpy(store[14].url, "X");
	strcpy(store[14].name, "���ʹ�");
	store[14].price = 10000;
	store[14].type = 0;
	store[14].type_eat = 2;
	store[14].store_to_pos_dist = 131;
	store[14].second_near = 204;
	store[14].store_to_sec_dist = 283;

	//�����
	store[15].position = 205;
	strcpy(store[15].url, "X");
	strcpy(store[15].name, "�����");
	store[15].price = 15000;
	store[15].type = 0;
	store[15].type_eat = 2;
	store[15].store_to_pos_dist = 201;
	store[15].second_near = 204;
	store[15].store_to_sec_dist = 317;

	//ī�� ��ȭ��
	store[16].position = 205;
	strcpy(store[16].url, "X");
	strcpy(store[16].name, "ī�� ��ȭ��");
	store[16].price = 8000;
	store[16].type = 3;
	store[16].type_eat = 0;
	store[16].store_to_pos_dist = 182;
	store[16].second_near = 204;
	store[16].store_to_sec_dist = 298;

	//�����Ϸ��� ���ī���� 
	store[17].position = 205;
	strcpy(store[17].url, "X");
	strcpy(store[17].name, "�����Ϸ��� ���ī����");
	store[17].price = 0;
	store[17].type = 2;
	store[17].type_eat = 0;
	store[17].store_to_pos_dist = 185;
	store[17].second_near = 204;
	store[17].store_to_sec_dist = 287;

	//���ο´����౹
	store[18].position = 205;
	strcpy(store[18].url, "X");
	strcpy(store[18].name, "���ο´����౹");
	store[18].price = 0;
	store[18].type = 1;
	store[18].type_eat = 0;
	store[18].store_to_pos_dist = 185;
	store[18].second_near = 204;
	store[18].store_to_sec_dist = 287;

	//âȭ��
	store[19].position = 205;
	strcpy(store[19].url, "http://www.chdang.com");
	strcpy(store[19].name, "âȭ��");
	store[19].price = 10000;
	store[19].type = 0;
	store[19].type_eat = 1;
	store[19].store_to_pos_dist = 183;
	store[19].second_near = 204;
	store[19].store_to_sec_dist = 299;

	//��߻���̸�
	store[20].position = 205;
	strcpy(store[20].url, "http://www.menyasandaime.co.kr/");
	strcpy(store[20].name, "��߻���̸�");
	store[20].price = 8000;
	store[20].type = 0;
	store[20].type_eat = 2;
	store[20].store_to_pos_dist = 205;
	store[20].second_near = 204;
	store[20].store_to_sec_dist = 321;

	//��̽�
	store[21].position = 205;
	strcpy(store[21].url, "X");
	strcpy(store[21].name, "��̽�");
	store[21].price = 5000;
	store[21].type = 3;
	store[21].type_eat = 0;
	store[21].store_to_pos_dist = 181;
	store[21].second_near = 204;
	store[21].store_to_sec_dist = 297;

	//��ź��
	store[22].position = 205;
	strcpy(store[22].url, "http://butanchu.com");
	strcpy(store[22].name, "��ź��");
	store[22].price = 10000;
	store[22].type = 0;
	store[22].type_eat = 2;
	store[22].store_to_pos_dist = 255;
	store[22].second_near = 204;
	store[22].store_to_sec_dist = 309;

	//������
	store[23].position = 205;
	strcpy(store[23].url, "https://www.instagram.com/seoyangzip");
	strcpy(store[23].name, "������");
	store[23].price = 15000;
	store[23].type = 0;
	store[23].type_eat = 4;
	store[23].store_to_pos_dist = 255;
	store[23].second_near = 204;
	store[23].store_to_sec_dist = 309;

	//���ⶱ����
	store[24].position = 205;
	strcpy(store[24].url, "http://www.yupdduk.com/");
	strcpy(store[24].name, "���ⶱ����");
	store[24].price = 8000;
	store[24].type = 0;
	store[24].type_eat = 7;
	store[24].store_to_pos_dist = 162;
	store[24].second_near = 204;
	store[24].store_to_sec_dist = 283;

	//�δٱ��
	store[25].position = 205;
	strcpy(store[25].url, "X");
	strcpy(store[25].name, "�δٱ��");
	store[25].price = 8000;
	store[25].type = 0;
	store[25].type_eat = 1;
	store[25].store_to_pos_dist = 158;
	store[25].second_near = 204;
	store[25].store_to_sec_dist = 270;

	//Ĵ�ͽ�
	store[26].position = 205;
	strcpy(store[26].url, "X");
	strcpy(store[26].name, "Ĵ�ͽ�");
	store[26].price = 15000;
	store[26].type = 0;
	store[26].type_eat = 7;
	store[26].store_to_pos_dist = 140;
	store[26].second_near = 204;
	store[26].store_to_sec_dist = 260;

	//�������
	store[27].position = 214;
	strcpy(store[27].url, "http://www.bongchu.com");
	strcpy(store[27].name, "�������");
	store[27].price = 15000;
	store[27].type = 0;
	store[27].type_eat = 6;
	store[27].store_to_pos_dist = 187;
	store[27].second_near = 204;
	store[27].store_to_sec_dist = 289;

	//����ġŲ
	store[28].position = 205;
	strcpy(store[28].url, "http://www.kyochon.com/");
	strcpy(store[28].name, "����ġŲ");
	store[28].price = 20000;
	store[28].type = 0;
	store[28].type_eat = 6;
	store[28].store_to_pos_dist = 197;
	store[28].second_near = 204;
	store[28].store_to_sec_dist = 299;

	//ȣȣ�Ĵ�
	store[29].position = 205;
	strcpy(store[29].url, "https://www.instagram.com/hohosikdang/");
	strcpy(store[29].name, "ȣȣ�Ĵ�");
	store[29].price = 15000;
	store[29].type = 0;
	store[29].type_eat = 2;
	store[29].store_to_pos_dist = 197;
	store[29].second_near = 204;
	store[29].store_to_sec_dist = 299;

	//����
	store[30].position = 205;
	strcpy(store[30].url, "https://blog.naver.com/jungdon0916");
	strcpy(store[30].name, "����");
	store[30].price = 15000;
	store[30].type = 0;
	store[30].type_eat = 2;
	store[30].store_to_pos_dist = 302;
	store[30].second_near = 204;
	store[30].store_to_sec_dist = 318;

	//GS25 �����Ÿ��
	store[31].position = 204;
	strcpy(store[31].url, "X");
	strcpy(store[31].name, "GS25 �����Ÿ��");
	store[31].price = 0;
	store[31].type = 2;
	store[31].type_eat = 0;
	store[31].store_to_pos_dist = 231;
	store[31].second_near = 205;
	store[31].store_to_sec_dist = 237;

	//�޹������
	store[32].position = 204;
	strcpy(store[32].url, "https://www.instagram.com/memilhyang");
	strcpy(store[32].name, "�޹������");
	store[32].price = 15000;
	store[32].type = 0;
	store[32].type_eat = 6;
	store[32].store_to_pos_dist = 199;
	store[32].second_near = 205;
	store[32].store_to_sec_dist = 246;

	//�ɸ���
	store[33].position = 204;
	strcpy(store[33].url, "X");
	strcpy(store[33].name, "�ɸ���");
	store[33].price = 15000;
	store[33].type = 0;
	store[33].type_eat = 6;
	store[33].store_to_pos_dist = 198;
	store[33].second_near = 205;
	store[33].store_to_sec_dist = 245;

	//������ũ
	store[34].position = 204;
	strcpy(store[34].url, "http://www.burgerpark.co.kr/");
	strcpy(store[34].name, "������ũ");
	store[34].price = 15000;
	store[34].type = 0;
	store[34].type_eat = 4;
	store[34].store_to_pos_dist = 255;
	store[34].second_near = 205;
	store[34].store_to_sec_dist = 288;

	//Ŀ�ɱ׷糪��
	store[35].position = 204;
	strcpy(store[35].url, "X");
	strcpy(store[35].name, "Ŀ�ɱ׷糪��");
	store[35].price = 5000;
	store[35].type = 3;
	store[35].type_eat = 0;
	store[35].store_to_pos_dist = 179;
	store[35].second_near = 205;
	store[35].store_to_sec_dist = 301;

	//CU ���зα�����
	store[36].position = 204;
	strcpy(store[36].url, "X");
	strcpy(store[36].name, "CU ���зα�����");
	store[36].price = 0;
	store[36].type = 2;
	store[36].type_eat = 0;
	store[36].store_to_pos_dist = 220;
	store[36].second_near = 205;
	store[36].store_to_sec_dist = 356;

	//�������Ĵ�
	store[37].position = 204;
	strcpy(store[37].url, "http://newmaul.com");
	strcpy(store[37].name, "�������Ĵ�");
	store[37].price = 10000;
	store[37].type = 0;
	store[37].type_eat = 5;
	store[37].store_to_pos_dist = 204;
	store[37].second_near = 205;
	store[37].store_to_sec_dist = 303;

	//�Ķ����౹
	store[38].position = 204;
	strcpy(store[38].url, "X");
	strcpy(store[38].name, "�Ķ����౹");
	store[38].price = 0;
	store[38].type = 1;
	store[38].type_eat = 0;
	store[38].store_to_pos_dist = 221;
	store[38].second_near = 205;
	store[38].store_to_sec_dist = 357;

	//���������ʾ౹
	store[39].position = 204;
	strcpy(store[39].url, "X");
	strcpy(store[39].name, "���������ʾ౹");
	store[39].price = 0;
	store[39].type = 1;
	store[39].type_eat = 0;
	store[39].store_to_pos_dist = 234;
	store[39].second_near = 205;
	store[39].store_to_sec_dist = 370;

	//-----------------------���Ÿ�----------------------

	//�谡��
	store[40].position = 205;
	strcpy(store[40].url, "http://www.gimgane.co.kr");
	strcpy(store[40].name, "�谡��");
	store[40].price = 8000;
	store[40].type = 0;
	store[40].type_eat = 1;
	store[40].store_to_pos_dist = 45;
	store[40].second_near = 204;
	store[40].store_to_sec_dist = 218;

	//���û�ҿ�
	store[41].position = 205;
	strcpy(store[41].url, "X");
	strcpy(store[41].name, "���û�ҿ�");
	store[41].price = 15000;
	store[41].type = 0;
	store[41].type_eat = 2;
	store[41].store_to_pos_dist = 45;
	store[41].second_near = 204;
	store[41].store_to_sec_dist = 218;

	//ŷ����Ŀ��
	store[42].position = 205;
	strcpy(store[42].url, "X");
	strcpy(store[42].name, "ŷ����Ŀ��");
	store[42].price = 5000;
	store[42].type = 3;
	store[42].type_eat = 0;
	store[42].store_to_pos_dist = 27;
	store[42].second_near = 204;
	store[42].store_to_sec_dist = 264;

	//�����
	store[43].position = 205;
	strcpy(store[43].url, "X");
	strcpy(store[43].name, "�����");
	store[43].price = 15000;
	store[43].type = 0;
	store[43].type_eat = 6;
	store[43].store_to_pos_dist = 41;
	store[43].second_near = 204;
	store[43].store_to_sec_dist = 203;

	//��κδ��
	store[44].position = 205;
	strcpy(store[44].url, "https://www.nolboo.co.kr/pages/business/brand_boodae.asp");
	strcpy(store[44].name, "��κδ��");
	store[44].price = 10000;
	store[44].type = 0;
	store[44].type_eat = 1;
	store[44].store_to_pos_dist = 60;
	store[44].second_near = 204;
	store[44].store_to_sec_dist = 203;

	//������
	store[45].position = 205;
	strcpy(store[45].url, "X");
	strcpy(store[45].name, "������");
	store[45].price = 10000;
	store[45].type = 0;
	store[45].type_eat = 7;
	store[45].store_to_pos_dist = 63;
	store[45].second_near = 204;
	store[45].store_to_sec_dist = 181;

	//��Ź�Ǹ���
	store[46].position = 205;
	strcpy(store[46].url, "X");
	strcpy(store[46].name, "��Ź�Ǹ���");
	store[46].price = 8000;
	store[46].type = 0;
	store[46].type_eat = 1;
	store[46].store_to_pos_dist = 120;
	store[46].second_near = 204;
	store[46].store_to_sec_dist = 172;

	//�ö��׺��ͽ�������
	store[47].position = 205;
	strcpy(store[47].url, "http://flyingbowlexpress.com/");
	strcpy(store[47].name, "�ö��׺��ͽ�������");
	store[47].price = 8000;
	store[47].type = 0;
	store[47].type_eat = 4;
	store[47].store_to_pos_dist = 146;
	store[47].second_near = 204;
	store[47].store_to_sec_dist = 146;

	//���ɸ�
	store[48].position = 205;
	strcpy(store[48].url, "http://sanchome.co.kr");
	strcpy(store[48].name, "���ɸ�");
	store[48].price = 8000;
	store[48].type = 0;
	store[48].type_eat = 2;
	store[48].store_to_pos_dist = 146;
	store[48].second_near = 204;
	store[48].store_to_sec_dist = 146;

	//��ȸ�ѿ���
	store[49].position = 205;
	strcpy(store[49].url, "http://www.happysalmon.co.kr/");
	strcpy(store[49].name, "��ȸ�ѿ���");
	store[49].price = 15000;
	store[49].type = 0;
	store[49].type_eat = 5;
	store[49].store_to_pos_dist = 113;
	store[49].second_near = 204;
	store[49].store_to_sec_dist = 179;

	//��ȭ���౹
	store[50].position = 204;
	strcpy(store[50].url, "X");
	strcpy(store[50].name, "��ȭ���౹");
	store[50].price = 0;
	store[50].type = 1;
	store[50].type_eat = 0;
	store[50].store_to_pos_dist = 139;
	store[50].second_near = 205;
	store[50].store_to_sec_dist = 159;

	//���콺����ũ
	store[51].position = 204;
	strcpy(store[51].url, "http://tokyosteak.co.kr");
	strcpy(store[51].name, "���콺����ũ");
	store[51].price = 10000;
	store[51].type = 0;
	store[51].type_eat = 2;
	store[51].store_to_pos_dist = 145;
	store[51].second_near = 205;
	store[51].store_to_sec_dist = 177;

	//�Ϸ簡
	store[52].position = 205;
	strcpy(store[52].url, "X");
	strcpy(store[52].name, "�Ϸ簡");
	store[52].price = 10000;
	store[52].type = 0;
	store[52].type_eat = 7;
	store[52].store_to_pos_dist = 132;
	store[52].second_near = 204;
	store[52].store_to_sec_dist = 145;

	//ȥī��
	store[53].position = 204;
	strcpy(store[53].url, "X");
	strcpy(store[53].name, "ȥī��");
	store[53].price = 10000;
	store[53].type = 0;
	store[53].type_eat = 2;
	store[53].store_to_pos_dist = 103;
	store[53].second_near = 205;
	store[53].store_to_sec_dist = 195;

	//���͸������
	store[54].position = 204;
	strcpy(store[54].url, "X");
	strcpy(store[54].name, "���͸������");
	store[54].price = 10000;
	store[54].type = 0;
	store[54].type_eat = 5;
	store[54].store_to_pos_dist = 93;
	store[54].second_near = 205;
	store[54].store_to_sec_dist = 206;

	//ȫ�����
	store[108].position = 204;
	strcpy(store[108].url, "http://www.theborn.co.kr/theborn_brand/zzambbong");
	strcpy(store[108].name, "ȫ�����");
	store[108].price = 5000;
	store[108].type = 0;
	store[108].type_eat = 3;
	store[108].store_to_pos_dist = 90;
	store[108].second_near = 205;
	store[108].store_to_sec_dist = 208;

	//���ǵ���
	store[109].position = 204;
	strcpy(store[109].url, "X");
	strcpy(store[109].name, "���ǵ���");
	store[109].price = 10000;
	store[109].type = 0;
	store[109].type_eat = 7;
	store[109].store_to_pos_dist = 173;
	store[109].second_near = 205;
	store[109].store_to_sec_dist = 198;

	//CU���з�2ȣ��
	store[110].position = 204;
	strcpy(store[110].url, "X");
	strcpy(store[110].name, "CU���з�2ȣ��");
	store[110].price = 0;
	store[110].type = 2;
	store[110].type_eat = 0;
	store[110].store_to_pos_dist = 99;
	store[110].second_near = 205;
	store[110].store_to_sec_dist = 210;

	//������ġ
	store[111].position = 204;
	strcpy(store[111].url, "http://www.momstouch.co.kr");
	strcpy(store[111].name, "������ġ");
	store[111].price = 8000;
	store[111].type = 0;
	store[111].type_eat = 7;
	store[111].store_to_pos_dist = 103;
	store[111].second_near = 205;
	store[111].store_to_sec_dist = 214;

	//�����ֹ�
	store[112].position = 204;
	strcpy(store[112].url, "https://witchskitchen.co.kr");
	strcpy(store[112].name, "�����ֹ�");
	store[112].price = 20000;
	store[112].type = 0;
	store[112].type_eat = 4;
	store[112].store_to_pos_dist = 85;
	store[112].second_near = 205;
	store[112].store_to_sec_dist = 233;

	//��ū����
	store[113].position = 204;
	strcpy(store[113].url, "http://www.��ū����.com");
	strcpy(store[113].name, "��ū����");
	store[113].price = 12000;
	store[113].type = 0;
	store[113].type_eat = 5;
	store[113].store_to_pos_dist = 114;
	store[113].second_near = 205;
	store[113].store_to_sec_dist = 243;

	//��������
	store[114].position = 204;
	strcpy(store[114].url, "X");
	strcpy(store[114].name, "��������");
	store[114].price = 20000;
	store[114].type = 0;
	store[114].type_eat = 6;
	store[114].store_to_pos_dist = 83;
	store[114].second_near = 205;
	store[114].store_to_sec_dist = 256;

	//�Ҹ���Ŀ��
	store[115].position = 204;
	strcpy(store[115].url, "http://www.hollys.co.kr");
	strcpy(store[115].name, "�Ҹ���Ŀ��");
	store[115].price = 5000;
	store[115].type = 3;
	store[115].type_eat = 0;
	store[115].store_to_pos_dist = 21;
	store[115].second_near = 205;
	store[115].store_to_sec_dist = 278;

	//GS25��ȭ�����
	store[116].position = 204;
	strcpy(store[116].url, "X");
	strcpy(store[116].name, "GS25��ȭ�����");
	store[116].price = 0;
	store[116].type = 2;
	store[116].type_eat = 0;
	store[116].store_to_pos_dist = 77;
	store[116].second_near = 205;
	store[116].store_to_sec_dist = 277;

	//������
	store[117].position = 204;
	strcpy(store[117].url, "https://norangtongdak.co.kr/");
	strcpy(store[117].name, "������");
	store[117].price = 15000;
	store[117].type = 0;
	store[117].type_eat = 6;
	store[117].store_to_pos_dist = 84;
	store[117].second_near = 205;
	store[117].store_to_sec_dist = 279;

	//���׾�����ġŲ
	store[118].position = 204;
	strcpy(store[118].url, "X");
	strcpy(store[118].name, "���׾�����ġŲ");
	store[118].price = 25000;
	store[118].type = 0;
	store[118].type_eat = 6;
	store[118].store_to_pos_dist = 92;
	store[118].second_near = 205;
	store[118].store_to_sec_dist = 288;

	//---------------------�ʹ�--------------------------

	store[57].position = 202;
	strcpy(store[57].url, "X");
	strcpy(store[57].name, "����");
	store[57].price = 5000;
	store[57].type = 0;
	store[57].type_eat = 1;
	store[57].store_to_pos_dist = 89;
	store[57].second_near = 200;
	store[57].store_to_sec_dist = 475;

	store[56].position = 202;
	strcpy(store[56].url, "X");
	strcpy(store[56].name, "��������");
	store[56].price = 8000;
	store[56].type = 0;
	store[56].type_eat = 2;
	store[56].store_to_pos_dist = 90;
	store[56].second_near = 200;
	store[56].store_to_sec_dist = 476;

	store[66].position = 202;
	strcpy(store[66].url, "X");
	strcpy(store[66].name, "õ������������");
	store[66].price = 5000;
	store[66].type = 0;
	store[66].type_eat = 7;
	store[66].store_to_pos_dist = 182;
	store[66].second_near = 201;
	store[66].store_to_sec_dist = 609;

	store[55].position = 202;
	strcpy(store[55].url, "X");
	strcpy(store[55].name, "�Ķ�����");
	store[55].price = 8000;
	store[55].type = 0;
	store[55].type_eat = 7;
	store[55].store_to_pos_dist = 40;
	store[55].second_near = 200;
	store[55].store_to_sec_dist = 426;

	store[58].position = 202;
	strcpy(store[58].url, "X");
	strcpy(store[58].name, "��Ÿ���θ�");
	store[58].price = 8000;
	store[58].type = 0;
	store[58].type_eat = 2;
	store[58].store_to_pos_dist = 122;
	store[58].second_near = 200;
	store[58].store_to_sec_dist = 505;


	store[59].position = 202;
	strcpy(store[59].url, "X");
	strcpy(store[59].name, "û����ȭ");
	store[59].price = 8000;
	store[59].type = 0;
	store[59].type_eat = 1;
	store[59].store_to_pos_dist = 118;
	store[59].second_near = 200;
	store[59].store_to_sec_dist = 501;

	store[61].position = 202;
	strcpy(store[61].url, "X");
	strcpy(store[61].name, "�캸��");
	store[61].price = 8000;
	store[61].type = 0;
	store[61].type_eat = 3;
	store[61].store_to_pos_dist = 240;
	store[61].second_near = 201;
	store[61].store_to_sec_dist = 661;

	store[60].position = 202;
	strcpy(store[60].url, "X");
	strcpy(store[60].name, "��������");
	store[60].price = 10000;
	store[60].type = 0;
	store[60].type_eat = 4;
	store[60].store_to_pos_dist = 86;
	store[60].second_near = 200;
	store[60].store_to_sec_dist = 469;

	store[62].position = 202;
	strcpy(store[62].url, "www.bongousse.net/main.aspx");
	strcpy(store[62].name, "�����������");
	store[62].price = 5000;
	store[62].type = 0;
	store[62].type_eat = 1;
	store[62].store_to_pos_dist = 150;
	store[62].second_near = 201;
	store[62].store_to_sec_dist = 654;

	store[64].position = 202;
	strcpy(store[64].url, "X");
	strcpy(store[64].name, "����");
	store[64].price = 8000;
	store[64].type = 0;
	store[64].type_eat = 6;
	store[64].store_to_pos_dist = 223;
	store[64].second_near = 201;
	store[64].store_to_sec_dist = 644;

	store[63].position = 202;
	strcpy(store[63].url, "X");
	strcpy(store[63].name, "���ͺθ���");
	store[63].price = 5000;
	store[63].type = 0;
	store[63].type_eat = 7;
	store[63].store_to_pos_dist = 91;
	store[63].second_near = 200;
	store[63].store_to_sec_dist = 474;

	store[65].position = 202;
	strcpy(store[65].url, "X");
	strcpy(store[65].name, "���ر�");
	store[65].price = 8000;
	store[65].type = 0;
	store[65].type_eat = 2;
	store[65].store_to_pos_dist = 99;
	store[65].second_near = 200;
	store[65].store_to_sec_dist = 483;

	store[71].position = 202;
	strcpy(store[71].url, "https://www.facebook.com/koffisix");
	strcpy(store[71].name, "�꽺�Ľ�");
	store[71].price = 5000;
	store[71].type = 3;
	store[71].type_eat = 0;
	store[71].store_to_pos_dist = 139;
	store[71].second_near = 201;
	store[71].store_to_sec_dist = 560;

	store[70].position = 202;
	strcpy(store[70].url, "https://www.emart24.co.kr");
	strcpy(store[70].name, "�̸�Ʈ24������");
	store[70].price = 0;
	store[70].type = 2;
	store[70].type_eat = 0;
	store[70].store_to_pos_dist = 120;
	store[70].second_near = 200;
	store[70].store_to_sec_dist = 502;

	store[72].position = 202;
	strcpy(store[72].url, "gs25.gsretail.com");
	strcpy(store[72].name, "GS25���������");
	store[72].price = 0;
	store[72].type = 2;
	store[72].type_eat = 0;
	store[72].store_to_pos_dist = 298;
	store[72].second_near = 203;
	store[72].store_to_sec_dist = 367;

	store[69].position = 202;
	strcpy(store[69].url, "X");
	strcpy(store[69].name, "ž���θ�Ʈ");
	store[69].price = 0;
	store[69].type = 2;
	store[69].type_eat = 0;
	store[69].store_to_pos_dist = 253;
	store[69].second_near = 203;
	store[69].store_to_sec_dist = 401;

	store[67].position = 202;
	strcpy(store[67].url, "X");
	strcpy(store[67].name, "�����౹");
	store[67].price = 0;
	store[67].type = 1;
	store[67].type_eat = 0;
	store[67].store_to_pos_dist = 182;
	store[67].second_near = 201;
	store[67].store_to_sec_dist = 565;

	store[68].position = 202;
	strcpy(store[68].url, "X");
	strcpy(store[68].name, "�������౹");
	store[68].price = 0;
	store[68].type = 1;
	store[68].type_eat = 0;
	store[68].store_to_pos_dist = 320;
	store[68].second_near = 203;
	store[68].store_to_sec_dist = 374;




	//----------------����----------------------
	store[87].position = 203;
	strcpy(store[87].url, "www.cknia.com");
	strcpy(store[87].name, "ġŲ�ŴϾ�");
	store[87].price = 15000;
	store[87].type = 0;
	store[87].type_eat = 6;
	store[87].store_to_pos_dist = 132;
	store[87].second_near = 202;
	store[87].store_to_sec_dist = 536;

	store[88].position = 203;
	strcpy(store[88].url, "X");
	strcpy(store[88].name, "����3");
	store[88].price = 15000;
	store[88].type = 0;
	store[88].type_eat = 1;
	store[88].store_to_pos_dist = 377;
	store[88].second_near = 203;
	store[88].store_to_sec_dist = 947;

	store[74].position = 203;
	strcpy(store[74].url, "X");
	strcpy(store[74].name, "ȫ��â");
	store[74].price = 15000;
	store[74].type = 0;
	store[74].type_eat = 5;
	store[74].store_to_pos_dist = 137;
	store[74].second_near = 205;
	store[74].store_to_sec_dist = 236;

	store[104].position = 203;
	strcpy(store[104].url, "sinjeon.co.kr");
	strcpy(store[104].name, "����������");
	store[104].price = 5000;
	store[104].type = 0;
	store[104].type_eat = 7;
	store[104].store_to_pos_dist = 116;
	store[104].second_near = 205;
	store[104].store_to_sec_dist = 169;

	store[73].position = 203;
	strcpy(store[73].url, "X");
	strcpy(store[73].name, "����");
	store[73].price = 8000;
	store[73].type = 0;
	store[73].type_eat = 7;
	store[73].store_to_pos_dist = 265;
	store[73].second_near = 205;
	store[73].store_to_sec_dist = 34;

	store[80].position = 203;
	strcpy(store[80].url, "X");
	strcpy(store[80].name, "ȭ�λ�ȸ");
	store[80].price = 15000;
	store[80].type = 0;
	store[80].type_eat = 5;
	store[80].store_to_pos_dist = 134;
	store[80].second_near = 205;
	store[80].store_to_sec_dist = 206;

	store[78].position = 203;
	strcpy(store[78].url, "X");
	strcpy(store[78].name, "692�������");
	store[78].price = 20000;
	store[78].type = 0;
	store[78].type_eat = 5;
	store[78].store_to_pos_dist = 202;
	store[78].second_near = 205;
	store[78].store_to_sec_dist = 132;

	store[77].position = 203;
	strcpy(store[77].url, "http://www.ssaum.co.kr/");
	strcpy(store[77].name, "�ο��ǰ��");
	store[77].price = 10000;
	store[77].type = 0;
	store[77].type_eat = 5;
	store[77].store_to_pos_dist = 116;
	store[77].second_near = 205;
	store[77].store_to_sec_dist = 169;

	store[107].position = 203;
	strcpy(store[107].url, "www.mcdonalds.co.kr");
	strcpy(store[107].name, "�Ƶ�����");
	store[107].price = 8000;
	store[107].type = 0;
	store[107].type_eat = 7;
	store[107].store_to_pos_dist = 205;
	store[107].second_near = 314;
	store[107].store_to_sec_dist = 48;

	store[106].position = 203;
	strcpy(store[106].url, "pizzaschool.net");
	strcpy(store[106].name, "���ڽ���");
	store[106].price = 8000;
	store[106].type = 0;
	store[106].type_eat = 4;
	store[106].store_to_pos_dist = 143;
	store[106].second_near = 205;
	store[106].store_to_sec_dist = 156;

	store[103].position = 203;
	strcpy(store[103].url, "X");
	strcpy(store[103].name, "������");
	store[103].price = 5000;
	store[103].type = 0;
	store[103].type_eat = 1;
	store[103].store_to_pos_dist = 179;
	store[103].second_near = 205;
	store[103].store_to_sec_dist = 94;

	store[85].position = 203;
	strcpy(store[85].url, "X");
	strcpy(store[85].name, "����ո���");
	store[85].price = 5000;
	store[85].type = 0;
	store[85].type_eat = 7;
	store[85].store_to_pos_dist = 257;
	store[85].second_near = 205;
	store[85].store_to_sec_dist = 54;

	store[86].position = 203;
	strcpy(store[86].url, "http://milsup.co.kr/");
	strcpy(store[86].name, "�н�");
	store[86].price = 8000;
	store[86].type = 0;
	store[86].type_eat = 1;
	store[86].store_to_pos_dist = 293;
	store[86].second_near = 205;
	store[86].store_to_sec_dist = 27;

	store[81].position = 203;
	strcpy(store[81].url, "X");
	strcpy(store[81].name, "��ٽ���");
	store[81].price = 15000;
	store[81].type = 0;
	store[81].type_eat = 2;
	store[81].store_to_pos_dist = 265;
	store[81].second_near = 205;
	store[81].store_to_sec_dist = 34;

	store[105].position = 203;
	strcpy(store[105].url, "X");
	strcpy(store[105].name, "õ���");
	store[105].price = 15000;
	store[105].type = 0;
	store[105].type_eat = 3;
	store[105].store_to_pos_dist = 177;
	store[105].second_near = 205;
	store[105].store_to_sec_dist = 122;

	store[82].position = 203;
	strcpy(store[82].url, "http://www.ddingddong.co.kr/");
	strcpy(store[82].name, "��˿���");
	store[82].price = 5000;
	store[82].type = 3;
	store[82].type_eat = 0;
	store[82].store_to_pos_dist = 181;
	store[82].second_near = 205;
	store[82].store_to_sec_dist = 92;


	store[84].position = 203;
	strcpy(store[84].url, "ediya.com");
	strcpy(store[84].name, "�̵��");
	store[84].price = 5000;
	store[84].type = 3;
	store[84].type_eat = 0;
	store[84].store_to_pos_dist = 237;
	store[84].second_near = 205;
	store[84].store_to_sec_dist = 86;

	store[83].position = 203;
	strcpy(store[83].url, "www.tomntoms.com");
	strcpy(store[83].name, "Ž��Ž��");
	store[83].price = 5000;
	store[83].type = 3;
	store[83].type_eat = 0;
	store[83].store_to_pos_dist = 339;
	store[83].second_near = 205;
	store[83].store_to_sec_dist = 67;

	store[76].position = 203;
	strcpy(store[76].url, "www.emart24.co.kr");
	strcpy(store[76].name, "�̸�Ʈ24");
	store[76].price = 0;
	store[76].type = 2;
	store[76].type_eat = 0;
	store[76].store_to_pos_dist = 175;
	store[76].second_near = 205;
	store[76].store_to_sec_dist = 116;

	store[75].position = 203;
	strcpy(store[75].url, "www.7-eleven.co.kr");
	strcpy(store[75].name, "�����Ϸ��켺����");
	store[75].price = 0;
	store[75].type = 2;
	store[75].type_eat = 0;
	store[75].store_to_pos_dist = 123;
	store[75].second_near = 205;
	store[75].store_to_sec_dist = 207;

	store[79].position = 203;
	strcpy(store[79].url, "gs25.gsretail.com");
	strcpy(store[79].name, "GS25�����Ա���");
	store[79].price = 0;
	store[79].type = 2;
	store[79].type_eat = 0;
	store[79].store_to_pos_dist = 265;
	store[79].second_near = 205;
	store[79].store_to_sec_dist = 8;


	//-----------------------���з�----------------------------

	store[89].position = 206;
	strcpy(store[89].url, "http://abiko.kr/");
	strcpy(store[89].name, "�ƺ�ī��");
	store[89].price = 10000;
	store[89].type = 0;
	store[89].type_eat = 2;
	store[89].store_to_pos_dist = 177;
	store[89].second_near = 204;
	store[89].store_to_sec_dist = 291;

	store[90].position = 206;
	strcpy(store[90].url, "http://www.cocoichibanya.co.kr/");
	strcpy(store[90].name, "����������");
	store[90].price = 10000;
	store[90].type = 0;
	store[90].type_eat = 2;
	store[90].store_to_pos_dist = 110;
	store[90].second_near = 204;
	store[90].store_to_sec_dist = 198;

	store[92].position = 206;
	strcpy(store[92].url, "https://www.facebook.com/daepochicken");
	strcpy(store[92].name, "�������");
	store[92].price = 15000;
	store[92].type = 0;
	store[92].type_eat = 6;
	store[92].store_to_pos_dist = 303;
	store[92].second_near = 204;
	store[92].store_to_sec_dist = 383;

	store[98].position = 206;
	strcpy(store[98].url, "http://mpizzeriao.fordining.kr/");
	strcpy(store[98].name, "�������ƿ�");
	store[98].price = 20000;
	store[98].type = 0;
	store[98].type_eat = 4;
	store[98].store_to_pos_dist = 516;
	store[98].second_near = 204;
	store[98].store_to_sec_dist = 633;

	store[91].position = 206;
	strcpy(store[91].url, "X");
	strcpy(store[91].name, "���갡��");
	store[91].price = 20000;
	store[91].type = 0;
	store[91].type_eat = 5;
	store[91].store_to_pos_dist = 49;
	store[91].second_near = 204;
	store[91].store_to_sec_dist = 172;

	store[101].position = 206;
	strcpy(store[101].url, "X");
	strcpy(store[101].name, "�����ī������");
	store[101].price = 20000;
	store[101].type = 0;
	store[101].type_eat = 4;
	store[101].store_to_pos_dist = 235;
	store[101].second_near = 204;
	store[101].store_to_sec_dist = 352;

	store[100].position = 206;
	strcpy(store[100].url, "https://www.tokkijung.co.kr/");
	strcpy(store[100].name, "�䳢��");
	store[100].price = 15000;
	store[100].type = 0;
	store[100].type_eat = 7;
	store[100].store_to_pos_dist = 454;
	store[100].second_near = 204;
	store[100].store_to_sec_dist = 571;

	store[97].position = 206;
	strcpy(store[97].url, "X");
	strcpy(store[97].name, "���������");
	store[97].price = 10000;
	store[97].type = 0;
	store[97].type_eat = 7;
	store[97].store_to_pos_dist = 113;
	store[97].second_near = 204;
	store[97].store_to_sec_dist = 176;

	store[99].position = 206;
	strcpy(store[99].url, "https://www.kfckorea.com/");
	strcpy(store[99].name, "KFC");
	store[99].price = 8000;
	store[99].type = 0;
	store[99].type_eat = 7;
	store[99].store_to_pos_dist = 175;
	store[99].second_near = 204;
	store[99].store_to_sec_dist = 293;

	store[95].position = 206;
	strcpy(store[95].url, "http://www.emoikorea.com/");
	strcpy(store[95].name, "������");
	store[95].price = 10000;
	store[95].type = 0;
	store[95].type_eat = 7;
	store[95].store_to_pos_dist = 314;
	store[95].second_near = 204;
	store[95].store_to_sec_dist = 431;

	store[96].position = 206;
	strcpy(store[96].url, "http://www.nipongnaepong.co.kr/");
	strcpy(store[96].name, "�ϻͳ���");
	store[96].price = 10000;
	store[96].type = 0;
	store[96].type_eat = 4;
	store[96].store_to_pos_dist = 409;
	store[96].second_near = 204;
	store[96].store_to_sec_dist = 492;

	store[102].position = 206;
	strcpy(store[102].url, "sulbing.com");
	strcpy(store[102].name, "����");
	store[102].price = 5000;
	store[102].type = 3;
	store[102].type_eat = 0;
	store[102].store_to_pos_dist = 178;
	store[102].second_near = 204;
	store[102].store_to_sec_dist = 296;

	store[94].position = 206;
	strcpy(store[94].url, "X");
	strcpy(store[94].name, "��Ʈ�౹");
	store[94].price = 0;
	store[94].type = 1;
	store[94].type_eat = 0;
	store[94].store_to_pos_dist = 72;
	store[94].second_near = 204;
	store[94].store_to_sec_dist = 190;

	store[93].position = 206;
	strcpy(store[93].url, "cu.bgfretail.com");
	strcpy(store[93].name, "CU���ε�������");
	store[93].price = 0;
	store[93].type = 2;
	store[93].type_eat = 0;
	store[93].store_to_pos_dist = 116;
	store[93].second_near = 204;
	store[93].store_to_sec_dist = 234;


	//----------------------�ǹ�����--------------------------
	store[200].position = 200;
	strcpy(store[200].url, "X");
	strcpy(store[200].name, "�濵��");
	store[200].price = 0;
	store[200].type = 4;
	store[200].store_to_pos_dist = 0;
	store[200].second_near = 201;
	store[200].store_to_sec_dist = 92;

	store[201].position = 201;
	strcpy(store[201].url, "X");
	strcpy(store[201].name, "�߾ӵ�����");
	store[201].price = 0;
	store[201].type = 4;
	store[201].type_eat = 0;
	store[201].second_near = 202;
	store[201].store_to_pos_dist = 0;

	store[202].position = 202;
	strcpy(store[202].url, "X");
	strcpy(store[202].name, "�ʹ�����������");
	store[202].price = 0;
	store[202].type = 4;
	store[202].type_eat = 0;
	store[202].store_to_pos_dist = 0;


	store[203].position = 203;
	strcpy(store[203].url, "X");
	strcpy(store[203].name, "�б�����");
	store[203].price = 0;
	store[203].type = 4;
	store[203].type_eat = 0;
	store[203].store_to_pos_dist = 0;


	store[204].position = 204;
	strcpy(store[204].url, "X");
	strcpy(store[204].name, "��ȭ��4���ⱸ");
	store[204].price = 0;
	store[204].type = 4;
	store[204].type_eat = 0;
	store[204].store_to_pos_dist = 0;


	store[205].position = 205;
	strcpy(store[205].url, "X");
	strcpy(store[205].name, "�÷���Ÿ�");
	store[205].price = 0;
	store[205].type = 4;
	store[205].type_eat = 0;
	store[205].store_to_pos_dist = 0;


	store[206].position = 206;
	strcpy(store[206].url, "X");
	strcpy(store[206].name, "��ȭ��1���ⱸ");
	store[206].price = 0;
	store[206].type = 4;
	store[206].type_eat = 0;
	store[206].store_to_pos_dist = 0;


	store[207].position = 207;
	strcpy(store[207].url, "X");
	strcpy(store[207].name, "ȣ�ϰ�");
	store[207].price = 0;
	store[207].type = 4;
	store[207].type_eat = 0;
	store[207].store_to_pos_dist = 0;


	store[208].position = 208;
	strcpy(store[208].url, "X");
	strcpy(store[208].name, "������");
	store[208].price = 0;
	store[208].type = 4;
	store[208].type_eat = 0;
	store[208].store_to_pos_dist = 0;


	store[209].position = 209;
	strcpy(store[209].url, "X");
	strcpy(store[209].name, "������");
	store[209].price = 0;
	store[209].type = 4;
	store[209].type_eat = 0;
	store[209].store_to_pos_dist = 0;

	store[210].position = 210;
	strcpy(store[210].url, "X");
	strcpy(store[210].name, "������");
	store[210].price = 0;
	store[210].type = 4;
	store[210].type_eat = 0;
	store[210].store_to_pos_dist = 0;

	store[216].position = 216;
	strcpy(store[216].url, "X");
	strcpy(store[216].name, "600�ֳ����");
	store[216].price = 0;
	store[216].type = 4;
	store[216].store_to_pos_dist = 0;
	store[216].store_to_sec_dist = 0;
	return;
}
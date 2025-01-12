//#include "GenerateRandomNumber.h"
//
//int generateRandomNumber(int first, int last)
//{
//	// 운영체제가 제공하는 진짜 난수를 생성하도록 하는 시드값
//	// 진짜 난수의 경우 컴퓨터가 주변의 환경과 무작위적으로 상호작용하면서 
//	// 만들어지는 것이기 때문에 의사 난수보다 난수를 생성하는 속도가 매우 느림
//	// => 난수 엔진을 사용
//	random_device rd;
//	// 난수를 생성시켜주는 엔진
//	mt19937 generateEngine(rd());
//	// 난수 엔진이 난수를 뽑을 범위를 지정
//	uniform_int_distribution<int> randomNumber(first, last);
//
//	return randomNumber(generateEngine);
//}

﻿
#  TD&D Adventure
내일배움캠프 Unreal 1기 2조 팀 프로젝트입니다.

## 🔰 프로젝트 소개
>터미널 기반의 간단한 이야기 시뮬레이터입니다.
무작위, 자동으로 전투를 이어나가며 기록하게 됩니다.
플레이어가 할 수 있는 것은 전투 후 상점에서 구매/판매 뿐입니다.

## 🚧 개발 기간
>+  2025년 1월 10일 (금) ~ 2025년 1월 16일 (목)

### 👨‍👩‍👧‍👦 멤버 구성
>+ 정재훈 : GameManager 파트, 각자 다른 파트와의 코드 조율
>+ 김시현 : Character 파트, Inventory 포함, QA 작업
>+ 김주영 : Item, Shop 파트, 아이템 매매 기능 및 아이템 추가 
>+ 김재석 : Monster, Art 파트, 몬스터 추가 및 UI, 연출 작업

### 🛠️ 개발 도구 및 언어
>+ Visual Studio 2022 17.12.3
>+ C++

### 🎵 실행 방법
>+ 비주얼 스튜디오에 코드 복사 -> 빌드 -> 디버그
>+ 외부 라이브러리를 사용하지 않았기 때문에 별도의 작업 없이 실행 가능합니다.

### 🖼️ 프로젝트 미리보기
#### 컨셉
![스크린샷 2025-01-16 175441](https://github.com/user-attachments/assets/513c50cb-e96d-4c50-b2fa-065121a8ebe1)
![스크린샷 2025-01-16 180118](https://github.com/user-attachments/assets/68fd40b6-4154-4756-a017-a544b253adb1)
>+ 플레이어는 게임 속 세상에 이미 다녀온 적이 있습니다.
>+ 오래전 위기에 빠진 세상을 구해주고 기억을 잃은 채로 귀환한 플레이어.
>+ 플레이어가 그 세상에 가서 쓴 모험 저널을 출력해주는 컨셉입니다.
  
#### 구현 사항
![uml](https://teamsparta.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F83c75a39-3aba-4ba4-a792-7aefe4b07895%2F3fa1ee17-7874-4dc2-9e8a-97686677b5ac%2F2.png?table=block&id=b8702f46-1e71-424e-bcdb-0e657e01a1f0&spaceId=83c75a39-3aba-4ba4-a792-7aefe4b07895&width=1390&userId=&cache=v2)

### 🧩 핵심 로직/클래스 설명
프로젝트의 기반은 발제에 포함된 UML입니다. 해당 UML을 우선적으로 만들고, 개발 도중 필요와 선택에 따라 멤버를 추가/변경하였습니다.
>+ Character
<br>플레이어 객체를 생성합니다. 싱글톤 패턴으로 디자인되었습니다.
>+ GameManager
<br>게임의 관리자 클래스입니다. 게임의 진행상황을 관리합니다. 거의 대부분의 클래스와 상호작용합니다.
>+ Item
<br>아이템 인터페이스입니다. HealthPotion, ExperienceBoost, AttackBoost 에서 이를 구현합니다.
>+Shop
<br>상점을 관리하는 클래스입니다. 전투후 전리품을 매매할 수 있습니다.
>+ Monster
<br>몬스터 인터페이스입니다. Slime, Goblin, Orc, Troll, Bandit, BossMonster에서 구현합니다.

### 📌 과제 추가 구현사항 (파트별 분류)
>GameManager
>+ 몬스터별 처치 카운터 추가 - 몬스터 인스턴스 delete 전에, countKilledMonster 함수에 이름을 전달하여 몬스터 식별 -> 카운트 증가
>+ 난수 생성기 추가 - random_device()과 generateEngine을 이용한 난수 생성기(함수) 생성하여 각 클래스에서 활용
>+ 중단점 설정 - 플레이어 편의와 가시성을 위해 게임진행 중간중간 getch()로 입력대기 설정


>Character
>+ 슈퍼계정 - 히든 캐릭터. 생성자에서 특정 인자를 감지하면 초기 스테이터스가 뻥튀기되도록 설정.
>+ 인벤토리 정렬 기능 - 획득 순서에 상관없이 분류별로 나열하여 소지 아이템 확인이 편하게 함


>Item, Shop
>+ 부정적 아이템 추가 - 아이템 랜덤 사용에서 착안하여 체력과 공격력에 부정적 영향을 주는 아이템 추가
>+ 부정적 아이템 제거 비용 발생 - 상점에서 판매시 오히려 비용을 지불해야함 (저주 제거 느낌)
>+ 경험치 추가 아이템 - 대량, 소량으로 경험치를 더해주는 아이템 추가
>+ 리롤 기능 추가 - 상점 방문시 4종류의 무작위 아이템 구매가능. 1회에 한해 다시 무작위 호출


>Monster
>+ 몬스터별 보정치 추가 - 밸런싱 수단. 몬스터 개체(종족) 자체의 따라 강함을 표현
>+ 추가 몬스터 - 산적
>+ 몬스터별 개체명 추가 - 오크, 고블린, 산적은 생성시 무작위 이름을 가지고 태어납니다.
>+ 보스 몬스터 연출 추가 - 보스전 진입시 몬스터의 아스키아트 출력


>Art
>+ 배경음악 추가 - 게임 진행 상황별 음악 추가
>+ UI 설정 - 게임 컨셉에 맞는 인터페이스 설정
>+ 연출에 필요한 함수 추가 - 텍스트를 원하는 장소에 출력하기 위한 관련 함수들 추가하여 활용

### 🚧주의사항
터미널 크기 ( 열 120 행 30 ) 기준으로 제작되었습니다.

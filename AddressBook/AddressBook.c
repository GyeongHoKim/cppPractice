#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////
//주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "Adress.dat"

//////////////////////
void ReleaseList();

//////////////////////
typedef struct _USERDATA
{
    char szName[32];
    char szPhone[32];
    
    struct _USERDATA *pNext;
} USERDATA;

// 더미 헤드 노드 선언 및 정의
USERDATA g_Head = {0};

//////////////////////
// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA *FindNode(char *pszName)
{
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL) {
        if(strcmp(pTmp->szName, pszName) == 0)
            return pTmp;
        
        //다음 노드로 이동
        pTmp = pTmp->pNext;
    }
    
    //일치하는 데이터를 찾지 못한 경우
    return NULL;
}

//////////////////////
int AddNewNode(char *pszName, char *pszPhone)
{
    USERDATA *pNewUer = NULL;
    
    //같은 이름이 이미 존재하는지 확인
    if(FindNode(pszName) != NULL)
        return 0;
    
    //메모리를 확보한다
    pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
    memset(pNewUser, 0, sizeof(USERDATA));
    
    //메모리에 값을 저장한다
    sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
    sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
    pNewUser->pNext = NULL;
    
    //더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에
    //추가한 데이터가 가장 앞쪽에 온다.
    pNewUser->pNext = g_Head.pNext;
    g_Head.pNext = pNewUser;
    
    return 1;
}

/////////////////////
//이름을 입력받아 리스트에 추가하는 함수
void Add()
{
    char szName[32] = {0};
    char szPhone[32] = {0};
    
    printf("Input name : ");
    fflush(stdin);
    gets_s(szName, sizeof(szName));
    
    printf("Input phone number : ");
    fflush(stdin);
    gets_s(szPhone, sizeof(szPhone));
    
    //실제로 리스트에 추가한다
    AddNewNode(szName, szPhone);
}

/////////////////////
//특정 노드를 검색하는 함수
void Search()
{
    char szName[32] = {0};
    USERDATA *pNode = NULL;
    
    printf("Input name : ");
    fflush(stdin);
    gets_s(szName, sizeof(szName));
    
    pNode = FindNode(szName);
    if(pNode != NULL) {
        printf"[%p] %s\t%s [%p]\n",
            pNode,
            pNode->szName, pNode->szPhone,
            pNode->pNext);
    }
    
    else {
        puts("ERROR data not found");
    }
    
    _getch();
}

/////////////////////
//리스트에 들어있는 모든 데이터를 화면에 출력하는 ㅏㅁ수
void PrintAll()
{
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL) {
        printf("[%p] %s\t%s [%p]\n",
            pTmp,
            pTmp->szName, pTmp->szPhone,
            pTmp->pNext);
            
        pTmp = pTmp->pNext;
    }
    
    _getch();
}

/////////////////////
//특정 노드를 검색하고 삭제하는 함수
int RemoveNode(char *pszName)
{
    USERDATA *pPrevNode = &g_Head;
    USERDATA *pDelete = NULL;
    
    while(pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;
        
        if(strcmp(pDelete->szName, pszName) == 0) {
            pPrevNode->pNext = pDelete->Next;
            free(pDelete);
            
            return 1;
        }
        
        pPrevNode = pPrevNode->pNext;
    }
    
    return 0;
}

//////////////////////
//이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
    char szName[32] = {0};
    
    printf("Input name : ");
    fflush(stdin);
    gets_s(szName, sizeof(szName));
    
    RemoveNode(szName);
}

/////////////////////
//메뉴를 출력하는 UI

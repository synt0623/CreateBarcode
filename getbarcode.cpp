#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "Shell32.lib")


#include <windows.h>
#include <string>
#include <stdio.h>
#include <winuser.h>
#include <shellapi.h>
//#include <fcntl.h>

BOOL RegisterApp(const wchar_t* windowID, WNDPROC windowProc);
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void MainDraw(HWND hWnd);
wchar_t **cmdline;  
int argc;



BOOL RegisterApp(const wchar_t* windowID, WNDPROC windowProc) {
    WNDCLASSEXW wc;
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = windowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = windowID;
    wc.hIconSm = (HICON)LoadImage(NULL,
                                  IDI_APPLICATION,
                                  IMAGE_ICON,
                                  0, 0, LR_DEFAULTSIZE | LR_SHARED);
    return (RegisterClassExW(&wc));
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    //static int iCount = 0;
    //static TCHAR strCount[8];
    //static HPEN hpen;
    static HWND button;
  
    switch (msg) {
    case WM_DESTROY:
        
        PostQuitMessage(0);
        return 0;

    case WM_CREATE:
        button = CreateWindow(
			L"BUTTON",
			L"OK",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 620, 100, 30,
			hWnd, (HMENU)1, ((LPCREATESTRUCT)(lp))->hInstance, NULL);

        return 0;
    
    case WM_PAINT:
        MainDraw(hWnd);
    
    case WM_COMMAND:
		switch (LOWORD(wp))
            {
            case 1:
                //onButtonCommand(hWnd, HIWORD(wp));//後述
                SendMessage(hWnd,WM_CLOSE , NULL, NULL);
                break;
            }


    case WM_KEYDOWN:
        switch(wp){
        case VK_RETURN:
            SendMessage(hWnd,WM_CLOSE , NULL, NULL);
            break;
            
        }
    }
    return DefWindowProc(hWnd, msg, wp, lp);
    
}


int WINAPI wWinMain(HINSTANCE hCurInst,
                    HINSTANCE hPrevInst,
                    LPWSTR lpsCmdLine,int nCmdShow){
    HWND hWnd;
    #ifdef _DEBUG_
    FILE* fpOut = NULL;
    if(! ::AttachConsole(ATTACH_PARENT_PROCESS)){
        ::AllocConsole();
    }
    ::freopen_s(&fpOut,"CONOUT$","w",stdout);
    #endif
    
    if (!RegisterApp(L"MyFirstApp", WndProc)) return FALSE;

    
    argc=0;
    cmdline = CommandLineToArgvW(GetCommandLine(), &argc);


    hWnd = CreateWindowW(L"MyFirstApp",
                         L"バーコード",
                         WS_OVERLAPPEDWINDOW,
                         100, 0, 600, 700,
                         NULL, NULL, hCurInst, NULL);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    MSG msg;
    BOOL value;
    while (TRUE){
        value = GetMessage(&msg,NULL,0,0);
        if( value == 0)break;
        if( value == -1)return 1;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    #ifdef _DEBUG_
    ::fclose(fpOut);
    fpOut=NULL;
    #endif
    LocalFree(cmdline);  
    return 0;
}

int ReturnKey(wchar_t a){

    if(a==L' ') return 0;
    if(a==L'!') return 1;
    if(a==L'"') return 2;
    if(a==L'#') return 3;
    if(a==L'$') return 4;
    if(a==L'%') return 5;
    if(a==L'&') return 6;
    if(a==L'\'') return 7;
    if(a==L'(') return 8;
    if(a==L')') return 9;
    if(a==L'*') return 10;
    if(a==L'+') return 11;
    if(a==L',') return 12;
    if(a==L'-') return 13;
    if(a==L'.') return 14;
    if(a==L'/') return 15;
    if(a==L'0') return 16;
    if(a==L'1') return 17;
    if(a==L'2') return 18;
    if(a==L'3') return 19;
    if(a==L'4') return 20;
    if(a==L'5') return 21;
    if(a==L'6') return 22;
    if(a==L'7') return 23;
    if(a==L'8') return 24;
    if(a==L'9') return 25;
    if(a==L':') return 26;
    if(a==L';') return 27;
    if(a==L'<') return 28;
    if(a==L'=') return 29;
    if(a==L'>') return 30;
    if(a==L'?') return 31;
    if(a==L'@') return 32;
    if(a==L'A') return 33;
    if(a==L'B') return 34;
    if(a==L'C') return 35;
    if(a==L'D') return 36;
    if(a==L'E') return 37;
    if(a==L'F') return 38;
    if(a==L'G') return 39;
    if(a==L'H') return 40;
    if(a==L'I') return 41;
    if(a==L'J') return 42;
    if(a==L'K') return 43;
    if(a==L'L') return 44;
    if(a==L'M') return 45;
    if(a==L'N') return 46;
    if(a==L'O') return 47;
    if(a==L'P') return 48;    
    if(a==L'Q') return 49;
    if(a==L'R') return 50;
    if(a==L'S') return 51;
    if(a==L'T') return 52;
    if(a==L'U') return 53;
    if(a==L'V') return 54;
    if(a==L'W') return 55;
    if(a==L'X') return 56;
    if(a==L'Y') return 57;
    if(a==L'Z') return 58;
    if(a==L'[') return 59;
    if(a==L'\\') return 60;
    if(a==L']') return 61;
    if(a==L'^') return 62;
    if(a==L'_') return 63;
    if(a==L'`') return 64;
    if(a==L'a') return 65;
    if(a==L'b') return 66;
    if(a==L'c') return 67;
    if(a==L'd') return 68;
    if(a==L'e') return 69;
    if(a==L'f') return 70;
    if(a==L'g') return 71;
    if(a==L'h') return 72;
    if(a==L'i') return 73;
    if(a==L'j') return 74;
    if(a==L'k') return 75;
    if(a==L'l') return 76;
    if(a==L'm') return 77;
    if(a==L'n') return 78;
    if(a==L'o') return 79;
    if(a==L'p') return 80;
    if(a==L'q') return 81;
    if(a==L'r') return 82;
    if(a==L's') return 83;
    if(a==L't') return 84;
    if(a==L'u') return 85;
    if(a==L'v') return 86;
    if(a==L'w') return 87;
    if(a==L'x') return 88;
    if(a==L'y') return 89;
    if(a==L'z') return 90;
    if(a==L'{') return 91;
    if(a==L'|') return 92;
    if(a==L'}') return 93;       
    if(a==L'~') return 94;
    return -1;
}



void ReturnCode(int key, int* code){
    if(key>106)return ;
    int dataarray[106][6] =  {
        {2,1,2,2,2,2}    // [0]->' '
        ,{2,2,2,1,2,2}   // [1]->'!'
        ,{2,2,2,2,2,1}   // [2]->'"'
        ,{1,2,1,2,2,3}   // [3]
        ,{1,2,1,3,2,2}   // [4]
        ,{1,3,1,2,2,2}   // [5]
        ,{1,2,2,2,1,3}   // [6]
        ,{1,2,2,3,1,2}   // [7]
        ,{1,3,2,2,1,2}   // [8]
        ,{2,2,1,2,1,3}   // [9]
        ,{2,2,1,3,1,2}   // [10]
        ,{2,3,1,2,1,2}   // [11]
        ,{1,1,2,2,3,2}   // [12]
        ,{1,2,2,1,3,2}   // [13]
        ,{1,2,2,2,3,1}   // [14]
        ,{1,1,3,2,2,2}   // [15]
        ,{1,2,3,1,2,2}   // [16]
        ,{1,2,3,2,2,1}   // [17]
        ,{2,2,3,2,1,1}   // [18]
        ,{2,2,1,1,3,2}   // [19]
        ,{2,2,1,2,3,1}   // [20]
        ,{2,1,3,2,1,2}   // [21]
        ,{2,2,3,1,1,2}   // [22]
        ,{3,1,2,1,3,1}   // [23]
        ,{3,1,1,2,2,2}   // [24]
        ,{3,2,1,1,2,2}   // [25]
        ,{3,2,1,2,2,1}   // [26]
        ,{3,1,2,2,1,2}   // [27]
        ,{3,2,2,1,1,2}   // [28]
        ,{3,2,2,2,1,1}   // [29]
        ,{2,1,2,1,2,3}   // [30]
        ,{2,1,2,3,2,1}   // [31]
        ,{2,3,2,1,2,1}   // [32]
        ,{1,1,1,3,2,3}   // [33]
        ,{1,3,1,1,2,3}   // [34]
        ,{1,3,1,3,2,1}   // [35]
        ,{1,1,2,3,1,3}   // [36]
        ,{1,3,2,1,1,3}   // [37]
        ,{1,3,2,3,1,1}   // [38]
        ,{2,1,1,3,1,3}   // [39]
        ,{2,3,1,1,1,3}   // [40]
        ,{2,3,1,3,1,1}   // [41]
        ,{1,1,2,1,3,3}   // [42]
        ,{1,1,2,3,3,1}   // [43]
        ,{1,3,2,1,3,1}   // [44]
        ,{1,1,3,1,2,3}   // [45]
        ,{1,1,3,3,2,1}   // [46]
        ,{1,3,3,1,2,1}   // [47]
        ,{3,1,3,1,2,1}   // [48]
        ,{2,1,1,3,3,1}   // [49]
        ,{2,3,1,1,3,1}   // [50]
        ,{2,1,3,1,1,3}   // [51]
        ,{2,1,3,3,1,1}   // [52]
        ,{2,1,3,1,3,1}   // [53]
        ,{3,1,1,1,2,3}   // [54]
        ,{3,1,1,3,2,1}   // [55]
        ,{3,3,1,1,2,1}   // [56]
        ,{3,1,2,1,1,3}   // [57]
        ,{3,1,2,3,1,1}   // [58]
        ,{3,3,2,1,1,1}   // [59]
        ,{3,1,4,1,1,1}   // [60]
        ,{2,2,1,4,1,1}   // [61]
        ,{4,3,1,1,1,1}   // [62]
        ,{1,1,1,2,2,4}   // [63]
        ,{1,1,1,4,2,2}   // [64]
        ,{1,2,1,1,2,4}   // [65]
        ,{1,2,1,4,2,1}   // [66]
        ,{1,4,1,1,2,2}   // [67]
        ,{1,4,1,2,2,1}   // [68]
        ,{1,1,2,2,1,4}   // [69]
        ,{1,1,2,4,1,2}   // [70]
        ,{1,2,2,1,1,4}   // [71]
        ,{1,2,2,4,1,1}   // [72]
        ,{1,4,2,1,1,2}   // [73]
        ,{1,4,2,2,1,1}   // [74]
        ,{2,4,1,2,1,1}   // [75]
        ,{2,2,1,1,1,4}   // [76]
        ,{4,1,3,1,1,1}   // [77]
        ,{2,4,1,1,1,2}   // [78]
        ,{1,3,4,1,1,1}   // [79]
        ,{1,1,1,2,4,2}   // [80]
        ,{1,2,1,1,4,2}   // [81]
        ,{1,2,1,2,4,1}   // [82]
        ,{1,1,4,2,1,2}   // [83]
        ,{1,2,4,1,1,2}   // [84]
        ,{1,2,4,2,1,1}   // [85]
        ,{4,1,1,2,1,2}   // [86]
        ,{4,2,1,1,1,2}   // [87]
        ,{4,2,1,2,1,1}   // [88]
        ,{2,1,2,1,4,1}   // [89]
        ,{2,1,4,1,2,1}   // [90]
        ,{4,1,2,1,2,1}   // [91]
        ,{1,1,1,1,4,3}   // [92]
        ,{1,1,1,3,4,1}   // [93]
        ,{1,3,1,1,4,1}   // [94]
        ,{1,1,4,1,1,3}   // [95]
        ,{1,1,4,3,1,1}   // [96]
        ,{4,1,1,1,1,3}   // [97]
        ,{4,1,1,3,1,1}   // [98]
        ,{1,1,3,1,4,1}   // [99]
        ,{1,1,4,1,3,1}   // [100]
        ,{3,1,1,1,4,1}   // [101]
        ,{4,1,1,1,3,1}   // [102]
        ,{2,1,1,4,1,1}   // [103]
        ,{2,1,1,2,1,4}   // [104]
        ,{2,1,1,2,3,2}   // [105]
    };
    
    char index = 0;

    for(int t=0;t<6;t++){
        code[t]=2*dataarray[key][t];
    }
}

void MainDraw(HWND hWnd){
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hpenB,hpenW ,hpenprev;
    HBRUSH hbrB,hbrW,hbrprev;

    int temp1=2;
    int start_b[6] = {2*temp1,1*temp1,1*temp1,2*temp1,1*temp1,4*temp1};
    int stop[7]={2*temp1,3*temp1,3*temp1,1*temp1,1*temp1,1*temp1,2*temp1};
    int data[6];
    
    //wchar_t* ccc = GetCommandLine();
    //wprintf(L"%s\n",ccc);
    //    for(int t=1;t<argc;t++) wprintf(L"%s\n",cmdline[t]);
    
    int maxarg=4;
    if(argc<4) maxarg=argc;
    
    hdc = BeginPaint(hWnd , &ps);  
    hpenB = CreatePen(PS_SOLID,1,RGB(0,0,0));
    hbrB = CreateSolidBrush(RGB(0,0,0));
    hpenW = CreatePen(PS_SOLID,1,RGB(250,250,250));
    hbrW = CreateSolidBrush(RGB(250,250,250));
    hpenprev = (HPEN)SelectObject(hdc,hpenB);
    hbrprev = (HBRUSH)SelectObject(hdc,hbrB);

    int pos_y=10;
    int pos_x;
    int y_len = 150;

    RECT rect;
    for(int i=1;i<maxarg;i++){    
        pos_x=30;
        int arglength=lstrlenW(cmdline[i]);
        rect.top=pos_y;
        rect.left=pos_x;
        for(int t=0;t<6;t++){
            if(t%2==0){
                SelectObject(hdc,hpenB);
                SelectObject(hdc,hbrB);
            }else{
                SelectObject(hdc,hpenW);
                SelectObject(hdc,hbrW);
            }
            Rectangle(hdc, pos_x, pos_y,
                      pos_x+start_b[t], pos_y+y_len);
            pos_x += (start_b[t]);
        }
        int key=0;
        int sum=0;
        for(int j=0;j<arglength;j++){
            key = ReturnKey(cmdline[i][j]);

            ReturnCode(key,data);
            sum = sum+(j+1)*key;
            for(int t=0;t<6;t++){
                if(t%2==0){
                    SelectObject(hdc,hpenB);
                    SelectObject(hdc,hbrB);
                }else{
                    SelectObject(hdc,hpenW);
                    SelectObject(hdc,hbrW);
                }
                Rectangle(hdc, pos_x, pos_y,
                          pos_x+data[t], pos_y+y_len);
                pos_x += (data[t]);
            }
        }

        sum += 104;

        ReturnCode(sum%103,data);
        for(int t=0;t<6;t++){
            if(t%2==0){
                SelectObject(hdc,hpenB);
                SelectObject(hdc,hbrB);
            }else{
                SelectObject(hdc,hpenW);
                SelectObject(hdc,hbrW);
            }
            Rectangle(hdc, pos_x, pos_y,
                      pos_x+data[t], pos_y+y_len);
            pos_x += (data[t]);
        }
            
        for(int t=0;t<7;t++){
            if(t%2==0){
                SelectObject(hdc,hpenB);
                SelectObject(hdc,hbrB);
            }else{
                SelectObject(hdc,hpenW);
                SelectObject(hdc,hbrW);
            }
            Rectangle(hdc, pos_x, pos_y,
                      pos_x+stop[t],pos_y+y_len);
            pos_x += (stop[t]);
        }

        SetTextAlign(hdc,TA_CENTER|TA_BASELINE);
        //GetClientRect(hWnd,&rect);
        rect.bottom = pos_y+y_len;
        rect.right = pos_x;
        
        TextOut(hdc,(rect.left+rect.right)/2,
                rect.bottom,
                cmdline[i],arglength);


        
        pos_y+=y_len+50;
    }
    SelectObject(hdc,hpenprev);
    SelectObject(hdc,hbrprev);
    DeleteObject(hpenB);
    DeleteObject(hpenW);
    DeleteObject(hbrB);
    DeleteObject(hbrW);

      
  
    EndPaint(hWnd , &ps);


}




 

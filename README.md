# CreateBarcode
引数文字列をバーコードにする。<br>
引数に与えることができる文字列は、3つまで有効。(バーコードを３つ表示する)。<br>
生成されるバーコードは、Code128 (CODE B)。<br>
<br>

## コンパイル方法 
Visual Studio Build Toolsがインストール済み。<br>
cl /D UNICODE /utf-8 /O2 /MT .\getbarcode.cpp /link /NODEFAULTLIB:libucrt.lib  /DEFAULTLIB:ucrt.lib <br>
<br>



## 動作環境
 Windows<br>
 (WinPE含む)<br>
<br>



## 実行方法
コマンドプロンプトから、引数で指定する<br>





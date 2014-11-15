#ifndef HSTRING_H
#define HSTRING_H

#include <iostream>

typedef struct {
	char *ch;
	int len;
}

void StrAssign(HString &S,char* chars){
	int i;
	if(T.ch) free(T.ch);
	for(i=0;chars[i]!='\0';i++);
	if(!i) {T.ch=NULL;  T.len=0;}
	else{
		if(!(T.ch=(char*)malloc(sizeof(char)*i))){
			exit(0);
		}
		T.len=i;
		for(i=0;i<T.len;i++){
			T.ch[i+1]=chars[i];
		}
	}
}

int StrLength(HString S){
	return S.len;
}

void StrCompare(HString S,HString H){
	int i;
	for(i=0;i<S.len&&i<T.len;i++){
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];
	}
	return S.len-T.len;
}

void ClearString(HString &S){
	if(S.ch){
		free(S.ch);
		S.ch=NULL;
	}
	S.len=0;
}

void Concat(HString &T,HString S1,HString S2){
	int i;
	if(T.ch) free(T.ch);
	if(!(T.ch=(char*)malloc(sizeof(char)*(S1.len+S2.len))))  exit(0);
	for(i=0;i<S1.len;i++)	T[i]=S1[i];
	for(i=0;i<S2.len;i++)	T[i+S1.len]=S2[i];
	T.len=S1.len+S2.len;
}

void SubString(HString &Sub,HString S,int pos,int len){
	if(pos>0&&pos<=S.len&&len>=0&&len<=S.len-pos+1){
		if(Sub.ch)	free(Sub.ch);
		if(!len){
			Sub.ch=NULL;
			Sub.len=0;
		}else{
			Sub.ch=(char*)malloc(sizeof(char)*len);
			if(!Sub.ch)	exit(0);
			int i;
			for(i=0;i<len;i++){
				Sub.ch[i]=S.ch[i+pos];
			}
			Sub.len=len;
		}
	}
}

//Index with KMP
void Index(HString S,HString T,int pos){
	int next[T.len-1];
	get_next(T,next);
	int i=pos-1,j=0;
	while(i<S.len&&j<T.len){
		if(j==0||S[i]==T[j]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	if(j>T.len-1) return i-T.len;
	else return 0;
}

void get_next(HString T,int next[]){
	int i=0,next[0]=0,j=0;
	while(i<T.len-1){
		if(j==0||T[i]==T[j]){
			i++;j++;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
}//get_next	

#endif

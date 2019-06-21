#include<stdio.h>
#include<string.h>

int main()
{
	FILE * fp=fopen("tmp.gdf","r");

	char tmp[512],a[100],b[100],c[100],d[100],e[100],f[100],g[100];

	fscanf(fp,"%[^\n]\n",tmp);

	strcpy(a,strtok(tmp,"|"));
	strcpy(b,strtok(NULL,"|"));
	strcpy(c,strtok(NULL,"|"));
	strcpy(d,strtok(NULL,"|"));
	strcpy(e,strtok(NULL,"|"));
	strcpy(f,strtok(NULL,"|"));
	strcpy(g,strtok(NULL,"|"));
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a,b,c,d,e,f,g);
}

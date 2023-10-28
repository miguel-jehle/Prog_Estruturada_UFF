#include <stdio.h>

int main(void){
    int hi, mi, hf, mf, resp;
    do{
        scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
        if (hi > hf && mi <= mf){
            resp = (24 -(hi-hf))*60 + (mf-mi);
        }else if(hi >= hf && mi > mf){
            resp = (24 -(hi-hf))*60 - (mi-mf);
        }else if(hi < hf && mi >= mf){
            resp = (hf-hi)*60 - (mi-mf);
        }else if(hi <= hf && mi < mf){
            resp = (hf-hi)*60 + (mf-mi);
        }
        if (hi!=0 || hf!=0 || mi!=0 || mf!=0){
            printf("%d\n", resp);
        }

    }while(hi!=0 || hf!=0 || mi!=0 || mf!=0);
}


/*

hi > hf && mi <= mf *
(24 -(diferença de hora))*60 + (mf-mi)

hi >= hf && mi > mf 
(24 -(diferença de hora))*60 - (mi-mf)

hi < hf && mi >= mf 
(hf-h1)*60 - (mi-mf)

hi <= hf && mi < mf 
(hf-hi)*60 + (mf-mi)



*/
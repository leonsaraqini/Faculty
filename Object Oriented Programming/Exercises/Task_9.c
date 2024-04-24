#include<stdio.h>
#include<string.h>
typedef struct Film{
    char name[100];
    int time;
    float price;
    int discount;
}Film;

typedef struct FilmFestival{
    char name[100];
    char place[100];
    Film films[100];
    int no;
}FilmFestival;

void print(FilmFestival f){
    printf("%s %s\n", f.name, f.place);

    for(int i = 0; i < f.no; i++){
        printf("%s %d %.2f\n", f.films[i].name, f.films[i].time, f.films[i].price);
    }
}

void bestFestival(FilmFestival *f, int n){
    int maxCountOfDiscounts = 0;
    int maxDurationOfAllFilms = 0;
    char name[100];
    char place[100];

    for(int i = 0; i < n; i++){
        int countOfDiscounts = 0;
        int durationOfAllFilms = 0;


        for(int j = 0; j < f[i].no; j++){
            if(f[i].films[j].discount)
                countOfDiscounts++;

            durationOfAllFilms += f[i].films[j].time;
        }

        if(countOfDiscounts > maxCountOfDiscounts || (countOfDiscounts == maxCountOfDiscounts && durationOfAllFilms > maxDurationOfAllFilms)){
            maxCountOfDiscounts = countOfDiscounts;
            maxDurationOfAllFilms = durationOfAllFilms;
            strcpy(name, f[i].name);
            strcpy(place, f[i].place);
        }
    }

    printf("Najdobar festival: %s %s", name, place);
}

int main()
{
    int i, j, n, broj;
    FilmFestival ff[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        /* name of the festival */
        scanf("%s", ff[i].name);
        /* place it is held */
        scanf("%s", ff[i].place);
        /* number of movies */
        scanf("%d", &ff[i].no);

        for (j = 0; j < ff[i].no; j++){
            scanf("%s", ff[i].films[j].name);  		/* title of the movie */
            scanf("%d", &ff[i].films[j].time); 		/* duration */
            scanf("%f", &ff[i].films[j].price); 	/* price */
            scanf("%d", &ff[i].films[j].discount);	/* discount */
        }
    }

    for(i=0; i<n; ++i){
        print(ff[i]);
    }

    bestFestival(ff, n);


    return 0;
}
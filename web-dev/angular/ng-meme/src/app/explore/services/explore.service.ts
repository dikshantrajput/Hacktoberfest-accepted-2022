import { environment } from './../../../environments/environment.prod';
import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { map, Observable } from 'rxjs';

export type Meme = {
  id: string;
  name: string;
  url: string;
  width: number;
  height: number;
  box_count: number;
};

@Injectable({
  providedIn: 'root',
})
export class ExploreService {
  memes = 'get_memes';
  constructor(private http: HttpClient) {}

  getMemes(): Observable<Meme[]> {
    return this.http
      .get(`${environment.api_endpoint}/${this.memes}`)
      .pipe(map((response: any) => response.data.memes));
  }
}

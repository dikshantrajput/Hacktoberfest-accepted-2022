import { Component, OnInit, ViewChild } from '@angular/core';
import { CommonModule } from '@angular/common';

import { componentImports } from './imports';
import { ExploreService, Meme } from './services/explore.service';
import { NgxMasonryComponent, NgxMasonryOptions } from 'ngx-masonry';

@Component({
  selector: 'app-explore',
  standalone: true,
  imports: [CommonModule, ...componentImports],
  templateUrl: './explore.component.html',
  styleUrls: ['./explore.component.scss'],
})
export class ExploreComponent implements OnInit {
  memes: Meme[] = [];

  layoutOption: NgxMasonryOptions = {
    gutter: 10
  };

  @ViewChild(NgxMasonryComponent) masonry?: NgxMasonryComponent;

  constructor(private exploreService: ExploreService) {}

  ngOnInit(): void {
    this.getMemes();
  }

  getMemes(): void {
    this.exploreService.getMemes().subscribe((response: Meme[]) => {
      this.memes = response;
      console.log(response, this.masonry);
      this.masonry?.reloadItems();
      this.masonry?.layout();
    });
  }
}

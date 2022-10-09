import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';

import { componentImports } from './imports';
import { ExploreService, Meme } from './services/explore.service';

@Component({
  selector: 'app-explore',
  standalone: true,
  imports: [CommonModule, ...componentImports],
  templateUrl: './explore.component.html',
  styleUrls: ['./explore.component.scss'],
})
export class ExploreComponent implements OnInit {
  memes: Meme[] = [];
  constructor(private exploreService: ExploreService) {}

  ngOnInit(): void {
    this.getMemes();
  }

  getMemes(): void {
    this.exploreService.getMemes().subscribe((response: Meme[]) => {
      this.memes = response;
      console.log(response)
    });
  }
}

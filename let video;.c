let video;
let scale = 1;
let rectSize;

function setup() {
  createCanvas(1280, 720);
  rectSize = scale * 0.5;
  //pixelDensity(1); // Ensure pixel density is set to 1 for proper pixel handling
  video = createCapture(VIDEO);
  video.size(1280, 720);
  video.hide(); // Hide the video element itself, use canvas for drawing
}

function draw() {
  if (video.loadedmetadata) { // Check if video is ready
    video.loadPixels();

    for (let i = 0; i < video.width; i += 20) {
      for (let j = 0; j < video.height; j += 5) {
        let pos = j * video.width + i;
        let pixelColor = video.pixels[pos * 4]; // p5.js stores pixel data in RGBA format
        
        let r = video.pixels[pos * 4 + 0];
        let g = video.pixels[pos * 4 + 1];
        let b = video.pixels[pos * 4 + 2];
        let alpha = video.pixels[pos * 4 + 3];
        
        let rR = random(200, 1000);
        let gR = random(20, 2000);
        let bR = random(200);

        noStroke();
        fill(r - i * rR / -8000, g - i * gR / 2100, b - i * bR / 1000, alpha);
        
        let i1 = random(-40, 10);
        let j1 = random(-5, 5);
        let posi = i * scale;
        let posj = j * scale;

        rect(posi + rectSize + i1, posj + j1, rectSize, rectSize); // Adjusted rect() call for p5.js
      }
    }

    video.updatePixels();
  }
}

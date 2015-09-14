var goodImg = 'images/good.jpg';
var worseImg = 'images/worse.jpg';
var worstImg = 'images/worst.jpg';

// self execute when it loaded
var exec = function () {
    draw();
}();

function imgOnLoaded() {
    /* Simply grabs a handle to the canvas element and
	 * check the context (Canvas support). 
	*/

	var canvas = document.getElementById('stong');
    var ctx = null;
    
    // Canvas supported?
    if (canvas.getContext) {
        
        ctx = canvas.getContext('2d');
        
        // Draw the loaded image onto the canvas
        ctx.drawImage(img, 0, 0);
        
    } else {
        alert("Canvas not supported!");
    }
}

function draw() {
    /* Main entry point got the thermometer Canvas example
	 * Simply grabs a handle to the canvas element and
	 * check the conect (Canvas support). 
	 */

	var canvas = document.getElementById('stong');
    
    // Create the image resource
    img = new Image();
    
    // Canvas supported?
    if (canvas.getContext) {
        // Setup the onload event
        img.onload = imgOnLoaded;
        
        // Load the image
        img.src = goodImg;
    } else {
        alert("Canvas not supported!");
    }
}

var stampColour = 'black';
var board = document.getElementById( "grid" );
var gridSize = 3;


function setStampColour( stamp )
{
    stampColour = stamp;
}

function setCellColour( cell )
{
    cell.style.backgroundColor = stampColour;
}

html = "";
for ( var i = 0; i < gridSize; i++ ) {
    html += '<div class="row">';
    for ( var j = 0; j < gridSize; j++ ) {
        // Letters from "K"
         var char = String.fromCharCode(75 + (i * gridSize + j));
         html += `<div class="cell" onclick="setCellColour(this)">${char}</div>`;
        // Letters from "A"
//         var char = String.fromCharCode(65 + (i * gridSize + j));
//         html += `<div class="cell" onclick="setCellColour(this)">${char}</div>`;
        // (i, j) grid coordinates
//         html += `<div class="cell" onclick="setCellColour(this)">(${i}, ${j})</div>`;
        // Blank cells
//         html += `<div class="cell" onclick="setCellColour(this)"></div>`;
    }
    html += '</div>';

}
board.innerHTML = html;



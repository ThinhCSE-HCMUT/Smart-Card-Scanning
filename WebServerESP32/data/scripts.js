async function fetchTable() {
    try {
        const response = await fetch("/table");
        const tableContent = await response.text();
        document.getElementById("tableBody").innerHTML = tableContent;
    } catch (error) {
        console.error("Error fetching table data:", error);
    }
}
setInterval(fetchTable, 2000);
fetchTable();
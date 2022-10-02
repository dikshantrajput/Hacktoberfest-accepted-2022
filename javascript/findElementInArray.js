//will return true if array contains 'hacktoberfest'
function findElementInArray(arr) {
    const hasHacktoberfet = arr.find(element => element === 'hacktoberfet');
    if(hasHacktoberfet) {
        return true;
    }
    return false;
}
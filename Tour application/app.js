const travelPackages = [
    {
        name: "Paris, France",
        price: "$1000",
        description: "Experience the romantic city of Paris."
    },
    {
        name: "Tokyo, Japan",
        price: "$1200",
        description: "Explore the vibrant culture of Tokyo."
    },
    {
        name: "Rome, Italy",
        price: "$1100",
        description: "Discover the ancient history of Rome."
    }
];

const travelPackagesContainer = document.getElementById('travel-packages');

function renderTravelPackages() {
    travelPackagesContainer.innerHTML = '';
    
    travelPackages.forEach(package => {
        const packageDiv = document.createElement('div');
        packageDiv.className = 'travel-package';
        packageDiv.innerHTML = `
            <h2>${package.name}</h2>
            <p><strong>Price:</strong> ${package.price}</p>
            <p>${package.description}</p>
        `;
        travelPackagesContainer.appendChild(packageDiv);
    });
}

renderTravelPackages();

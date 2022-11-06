# AutoShop

An auto shop needs an application where customers can search among the electric cars in the store and add them to their favourites.

Each electric car has an ID, a brand, a model, the year when it was registred, its mileage, its price, its loading time and its autonomy. 

The application can be used by a manager or by a client. The manager has permission to add, remove or update a car. He can search the repository of cars
and filter the search by brand, model, mileage or age. The manager can also opt to see all cars sorted by price. The client can add and remove cars from his
list of favourites. He can also filter the search in the car-repository by brand, model, mileage or age and also show all cars sorted by price.

The application has an OOP structure using its 4 principles of encapsuling, abstraction, inheritance and polymorphism. Smart-pointers are also used in 
the making of the app. The data is being saved locally through the InMemoryRepository or in a CSV file with the help of CSVRepository. Both Repositories have
CRUD functionalities..

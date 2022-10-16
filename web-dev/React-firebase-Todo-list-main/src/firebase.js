import {initializeApp} from 'firebase/app';
import {getFirestore} from 'firebase/firestore';

//firebase config
//To generate your own Firebase project and API key: https://firebase.google.com/docs/web/setup
//all the values in "" will be different when you create your own project so remember to replace the values
const firebaseConfig = {
    apiKey: "AIzaSyD_c5AJvOXuqlKt7iM5mBShbsbfxovPwXE",
    authDomain: "todo-list-e38ee.firebaseapp.com",
    projectId: "todo-list-e38ee",
    storageBucket: "todo-list-e38ee.appspot.com",
    messagingSenderId: "179324736343",
    appId: "1:179324736343:web:d0355ca39f1057c99fe412",
    measurementId: "G-D3ZELR77FR"
  };

const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

export {db};
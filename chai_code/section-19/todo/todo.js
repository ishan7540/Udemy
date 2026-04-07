const fs = require('fs');
const { takeCoverage } = require('v8');
const filePath = "./tasks.json";

const loadTasks = () => {
    try {
        const dataBuffer = fs.readFileSync(filePath);
        const dataJson = dataBuffer.toString();
        return JSON.parse(dataJson);
    } catch (error) {
        return []; // important fix
    }
}



const saveTasks = (tasks) => {
    const dataJSON = JSON.stringify(tasks);
    fs.writeFileSync(filePath, dataJSON);
}

const addTask = (task) => {
    const tasks = loadTasks();
    tasks.push({ task });
    saveTasks(tasks);
    console.log("Task added:", task);
}

const removeTasks = (index) =>{
    const tasks = loadTasks();
    tasks.splice(0,index-1);
    saveTasks(tasks);
}


const listTasks = () => {
    const tasks = loadTasks();
    for (x in tasks) {
        console.log(tasks[x]);
    }
}


const command = process.argv[2];
const argument = process.argv[3];

if (command === 'add') {
    addTask(argument);
} else if (command === 'list') {
    listTasks();
} else if (command === 'remove') {
    removeTasks(parseInt(argument));
} else {
    console.log("Command not recognised");
}
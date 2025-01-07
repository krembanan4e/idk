<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>
    <style>
        /*
na webhook ova:

[
{
"name": "Alice",
"level": "Senior",
"earnings": [
{"month": "January", "amount": 4000},
{"month": "February", "amount": 4200},
{"month": "March", "amount": 4500},
{"month": "April", "amount": 4800},
{"month": "May", "amount": 5000},
{"month": "June", "amount": 5100},
{"month": "July", "amount": 5300},
{"month": "August", "amount": 5200},
{"month": "September", "amount": 5000},
{"month": "October", "amount": 4900},
{"month": "November", "amount": 4800},
{"month": "December", "amount": 4700}
]
},
{
"name": "Bob",
"level": "Junior",
"earnings": [
{"month": "January", "amount": 1500},
{"month": "February", "amount": 1600},
{"month": "March", "amount": 1700},
{"month": "April", "amount": 1800},
{"month": "May", "amount": 1900},
{"month": "June", "amount": 2000},
{"month": "July", "amount": 2100},
{"month": "August", "amount": 2200},
{"month": "September", "amount": 2300},
{"month": "October", "amount": 2400},
{"month": "November", "amount": 2500},
{"month": "December", "amount": 2600}
]
},
{
"name": "Charlie",
"level": "Senior",
"earnings": [
{"month": "January", "amount": 3000},
{"month": "February", "amount": 3200},
{"month": "March", "amount": 3300},
{"month": "April", "amount": 3400},
{"month": "May", "amount": 3600},
{"month": "June", "amount": 3700},
{"month": "July", "amount": 3800},
{"month": "August", "amount": 3900},
{"month": "September", "amount": 4000},
{"month": "October", "amount": 4100},
{"month": "November", "amount": 4200},
{"month": "December", "amount": 4300}
]
},
{
"name": "Sarah",
"level": "Junior",
"earnings": [
{"month": "January", "amount": 1800},
{"month": "February", "amount": 1900},
{"month": "March", "amount": 2000},
{"month": "April", "amount": 2100},
{"month": "May", "amount": 2200},
{"month": "June", "amount": 2300},
{"month": "July", "amount": 2400},
{"month": "August", "amount": 2500},
{"month": "September", "amount": 2600},
{"month": "October", "amount": 2700},
{"month": "November", "amount": 2800},
{"month": "December", "amount": 2900}
]
}
]

*/
    </style>
</head>
<body>

<h1>Freelance Earnings Visualization</h1>
<button onclick="visualizeData()">Show All</button>
<button onclick="visualizeData('Senior')">Show Senior Developers</button>
<button onclick="visualizeData('Junior')">Show Junior Developers</button>
<div id="container" style="width: 1000px; height: 700px"></div>

<script>
    function visualizeData(level){
        let url = "https://webhook.site/83a21d0d-2146-4fa2-9993-c9ce65c641eb"
        fetch(url)
            .then(response => response.json())
            .then(function (data) {
                console.log(data)
                //var obj = JSON.stringify(data)
                //console.log(obj)
                //var obj2 = JSON.parse(obj)
                //console.log(obj2)

                let filteredData = data;

                if (level){
                    filteredData = data.filter(employee => employee.level === level)
                }

                let traces = []

                for (let i=0; i<filteredData.length; i++){
                    let trace = {
                        x: filteredData[i].earnings.map(earning => earning.month),
                        y: filteredData[i].earnings.map(earning => earning.amount),
                        type: 'markers+lines',
                        name: filteredData[i].name
                    }

                    traces.push(trace)
                }

                Plotly.newPlot("container", traces) //kade + niza
            })
    }

    visualizeData()

</script>
</body>
</html>

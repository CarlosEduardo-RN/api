import React, {Component} from 'react';
import {
    Pie, PieChart, Tooltip, ResponsiveContainer
} from 'recharts';

const data01 = [
    {
      "name": "LOCAL PARK",
      "value": 200
    },
    {
      "name": "L2+",
      "value": 300
    },
    {
      "name": "SANTA LÚCIA SUL",
      "value": 300
    },
    {
      "name": "ONE PARKING",
      "value": 200
    },
    {
      "name": "CASA DE SÃO PAULO",
      "value": 278
    },
    {
      "name": "BARÃO DO RIO BRANCO",
      "value": 189
    }
  ];
  const data02 = [
    {
      "name": "LOCAL PARK",
      "value": 2400
    },
    {
      "name": "L2+",
      "value": 4567
    },
    {
      "name": "SANTA LÚCIA SUL",
      "value": 1398
    },
    {
      "name": "ONE PARKING",
      "value": 9800
    },
    {
      "name": "CASA DE SÃO PAULO",
      "value": 3908
    },
    {
      "name": "BARÃO DO RIO BRANCO",
      "value": 4800
    }
  ];

class Pies extends Component {
  
  render () {
    return (
      
      <ResponsiveContainer width={'100%'} height="35%">
        <PieChart width={730} height={250}>
        <Pie 
            data={data01} 
            dataKey="value" 
            nameKey="name" 
            cx="50%" 
            cy="50%" 
            outerRadius={50} 
            fill="#8884d8" />
        <Pie 
            data={data02} 
            dataKey="value" 
            nameKey="name" 
            cx="50%" 
            cy="50%" 
            innerRadius={60} 
            outerRadius={80} 
            fill="#82ca9d" 
            label />
        
        <Tooltip/>
        </PieChart>
      </ResponsiveContainer>
    );
  }
}

export default Pies;

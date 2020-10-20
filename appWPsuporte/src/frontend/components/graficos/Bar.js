import React, {Component} from 'react';
import {
    BarChart, Bar, Tooltip, XAxis, YAxis, Legend, CartesianGrid, ResponsiveContainer
} from 'recharts';

const data = [
    {
      "name": "LOCAL PARK",
      "Hardware": 4000,
      "Software": 2400
    },
    {
      "name": "L2+",
      "Hardware": 3000,
      "Software": 1398
    },
    {
      "name": "SANTA LÚCIA SUL",
      "Hardware": 2000,
      "Software": 9800
    },
    {
      "name": "ONE PARKING",
      "Hardware": 2780,
      "Software": 3908
    },
    {
      "name": "CASA DE SÃO PAULO",
      "Hardware": 1890,
      "Software": 4800
    },
    {
      "name": "CITY OFFICE",
      "Hardware": 2390,
      "Software": 3800
    }
  ]

class Bars extends Component {
  
  render () {
    return (
      <ResponsiveContainer width={'100%'} height="55%">
        <BarChart width={300} height={250} data={data} 
        margin={{top: 55, right: 30, left: 20, bottom: 5}}>
          <CartesianGrid strokeDasharray="3 3" />
          <XAxis dataKey="name" />
          <YAxis />
          <Tooltip />
          <Legend />
          <Bar dataKey="Software" fill="#8884d8" />
          <Bar dataKey="Hardware" fill="#82ca9d" />
        </BarChart>
      </ResponsiveContainer>
    );
  }
}

export default Bars;


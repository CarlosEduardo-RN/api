import React, {Component} from 'react';
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
  ResponsiveContainer
} from 'recharts';

const data = [
  {name: '2020-05-14', ATENDIMENTOS: 2400, amt: 2400},
  {name: '2020-05-15', ATENDIMENTOS: 1398, amt: 2210},
  {name: '2020-05-16 ', ATENDIMENTOS: 9800, amt: 2290},
  {name: '2020-05-17 ', ATENDIMENTOS: 3908, amt: 2000},
  {name: '2020-05-18 ', ATENDIMENTOS: 4800, amt: 2181},
  {name: '2020-05-19 ', ATENDIMENTOS: 3800, amt: 2500},
  {name: '2020-05-20 ', ATENDIMENTOS: 4300, amt: 2100},
];

class Lines extends Component {
  
  render () {
    return (
      
      <ResponsiveContainer width={'100%'} height="55%">
        <LineChart
          width={600}
          height={300}
          data={data}
          margin={{top: 55, right: 30, left: 20, bottom: 5}}
          >
          <Line
            type='monotone'
            dataKey='ATENDIMENTOS'
            stroke='#8884d8'
            activeDot={{r: 6}}
            />
          <CartesianGrid strokeDasharray='3 3'/>
          <Tooltip/>
          <YAxis/>
          <XAxis dataKey='name'/>
          <Legend />
        </LineChart>
      </ResponsiveContainer>
    );
  }
}

export default Lines;